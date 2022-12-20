#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
	{
		count += putnbr(n / 10);
		count += putnbr(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}

int	ft_hex(unsigned int n)
{
	char *str = "0123456789abcdef";
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_hex(n / 16);
		count += ft_hex(n % 16);
	}
	else
	{
		ft_putchar(str[n]);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(arg, char *));
			else if (format[i] == 'd')
				count += putnbr(va_arg(arg, int));
			else if (format[i] == 'x')
				count += ft_hex(va_arg(arg, unsigned int));
			else if (format[i] == '%')
			{
				write (1, &format[i], 1);
				count++;
			}
		}
		i++;
	}
	va_end(arg);
	return (count);
}

int main()
{
	int c;
	int j;
	char a = NULL;
	int b = INT_MAX;
	int d = 424242;
	int x;
	int z;

	c = printf("%d\n", b);
	printf("%d\n", c);
	j = ft_printf("%d\n", b);
	printf("%d\n", j);
	c = printf("%s\n", a);
	printf("%d\n", c);
	j = ft_printf("%s\n", a);
	printf("%d\n", j);
	c = printf("%x\n", -777);
	printf("%d\n", c);
	j = ft_printf("%x\n", -777);
	printf("%d\n", j);
	ft_printf("salut");
}

/*
int main()
{
    int c;
    int d;
    char *s;
    d = -20;
    ft_printf("ft_printf int = %d\n%%", d);
    c = ft_printf("%s", s);
	printf("ft_print1 f: %d\n", c);
	c = printf("%s", s);
	printf("print1 f: %d\n", c);
    ft_printf("ft_printf hexa = %x\n", d);

    c = printf("ft_printf%% int = %d\n", d);
    printf("printf count = %d\n", c);
    c = printf("ft_printf string = %s\n", s);
    printf("printf count = %d\n", c);
    c = printf("ft_printf hexa = %x\n", d);
    printf("printf count = %d\n", c);
    printf("bon %%\n");
    ft_printf(" oebon %%");
	ft_printf("lol");
    return (0);
}
*/
