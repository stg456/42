#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_s(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int ft_d(int nb)
{
	int i = 0;
	char *s = "0123456789";

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
	{
		i += ft_d(nb / 10);
		i += ft_d(nb % 10);
	}
	if (nb < 10)
	{
		i += write(1, &s[nb % 10], 1);
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
		i += write(1, &s[nb % 16], 1);
	}
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list ptr;
	int i = 0;
	int res = 0;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				res += ft_s(va_arg(ptr, char *));
			else if (format[i] == 'd')
				res += ft_d(va_arg(ptr, long));
			else if (format[i] == 'x')
				res += ft_x(va_arg(ptr, unsigned int));
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (res);
}

int main()
{
	int a = -337;
	int b = -2147483648;
	char *s1 = "abcdefghi";
	char *s2 = NULL;
	unsigned int h1 = 42;
	unsigned int h2 = 424242;

	printf("res: %d %d %s %s %x %x\n", a, b, s1, s2, h1, h2);
	ft_printf("res: %d %d %s %s %x %x\n", a, b, s1, s2, h1, h2);
	return (0);
}

// parait bon