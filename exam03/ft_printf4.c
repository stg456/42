#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr(int nb)
{
	int i = 0;
	char c = nb + '0';

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		i++;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		write(1, &c, 1);	
		i++;
	}
	return (i);
}

int ft_puthex(unsigned int nb)
{
	char *s = "0123456789abcdef";
	int i = 0;

	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	if (nb < 16)
	{
		write(1, &s[nb], 1);
		i++;
	}
	return(i);
}

int ft_printf(const char *format, ... )
{
	int i = 0;
	int res = 0;
	va_list ptr;

	va_start(ptr, format);
	while (format[i])
	{
		if ((format[i] == '%') && (format[i + 1]))
		{
			i++;
			if (format[i] == 's')
				res += ft_putstr(va_arg(ptr, char *));
			else if (format[i] == 'd')
				res += ft_putnbr(va_arg(ptr, int));
			else if (format[i] == 'x')
				res += ft_puthex(va_arg(ptr, unsigned int));
			else
			{
				write(1, &format[i], 1);
				res ++;
			}
		}
		i++;
	}
	va_end(ptr);
	return (res);
}

int main()
{
    // int c;
    // int d;
    // char *s = "abcdefghi";
    // d = -20;
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    // ft_printf("ft_printf int = %d\n%%", d);
    // c = ft_printf("%s", s);
	// printf("ft_print1 f: %d\n", c);
	// c = printf("%s", s);
	// printf("print1 f: %d\n", c);
    // ft_printf("ft_printf hexa = %x\n", d);

    // c = printf("ft_printf%% int = %d\n", d);
    // printf("printf count = %d\n", c);
    // c = printf("ft_printf string = %s\n", s);
    // printf("printf count = %d\n", c);
    // c = printf("ft_printf hexa = %x\n", d);
    // printf("printf count = %d\n", c);
    // printf("bon %%\n");
    // ft_printf(" oebon %%");
	// ft_printf("lol");
    return (0);
}

// possible