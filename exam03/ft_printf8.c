#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_s(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_d(int nb)
{
	int i = 0;
	char c = nb + '0';

	if (nb < 0)
	{
		write(1, "-", 1);
		i++;
	}
	if (nb >= 10)
	{
		i += ft_d(nb / 10);
		i += ft_d(nb % 10);
	}
	if (nb < 10)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int ft_x(unsigned int nb)
{
	int i = 0;
	char *s = "0123456789abcdef";

	if (nb >= 16)
	{
		i += ft_x(nb / 16);
		i += ft_x(nb % 16);
	}
	if (nb < 16)
	{
		write(1, &s[nb], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list arg;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_s(va_arg(arg, char *));
			else if (format[i] == 'd')
				count += ft_d(va_arg(arg, int));
			else if (format[i] == 'x')
				count += ft_x(va_arg(arg, unsigned int));
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
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
	char *a = "abcdefghi";
	int b = 123;
	unsigned int c = 10;
	ft_printf("%s\n%d %x\n", a, b, c);
	printf("%s\n%d %x\n", a, b, c);
	// ft_printf("%d \n", b);
	// printf("%d \n", b);
	// ft_printf("%x \n", c);
	// printf("%x \n", c);
	return (0);
}