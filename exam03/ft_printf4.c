#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
	}
	if (nb > 10)
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
	int i = 0;
	int res = 0;
	va_list ptr;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				res += ft_s(va_arg(ptr, char *));
			else if (format[i] == 'd')
				res += ft_d(va_arg(ptr, int));
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
	int z = INT_MAX;
	printf("int max = %d\n", z);
	int o = INT_MIN;
	printf("int min = %d\n", o);
	int a = 2147483647;
	int b = -2147483648;
	char *s1 = "abcdefghi";
	char *s2 = NULL;
	int h1 = -42;
	unsigned int h2 = 2147483647;
	int r = 0;
	r = printf("int a = %d\n", a);
	printf("size a = %d\n", r);
	r = printf("int b = %d\n", b);
	printf("size b = %d\n", r);
	r = printf("s1 = %s\n", s1);
	printf("size s1 = %d\n", r);
	r = printf("s2 = %s\n", s2);
	printf("size s2 = %d\n", r);
	r = printf("h1 = %x\n", h1);
	printf("size h1 = %d\n", r);
	r = printf("h2 = %x\n", h2);
	printf("size h2 = %d\n", r);
	printf("___________\n");
	r = ft_printf("int a = %d\n", a);
	printf("size a = %d\n", r);
	r = ft_printf("int b = %d\n", b);
	printf("size b = %d\n", r);
	r = ft_printf("s1 = %s\n", s1);
	printf("size s1 = %d\n", r);
	r = ft_printf("s2 = %s\n", s2);
	printf("size s2 = %d\n", r);
	r = ft_printf("h1 = %x\n", h1);
	printf("size h1 = %d\n", r);
	r = ft_printf("h2 = %x\n", h2);
	printf("size h2 = %d\n", r);
	r = printf("res: %d %d %s %s %x %x\n", a, b, s1, s2, h1, h2);
	ft_printf("%d\n", r);
	r = ft_printf("res: %d %d %s %s %x %x\n", a, b, s1, s2, h1, h2);
	ft_printf("%d\n", r);

	return (0);
}