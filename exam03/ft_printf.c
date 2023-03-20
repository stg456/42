#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int put_s(char *str)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int put_d(long long nb)
{
	int i = 0;
	char *s = "0123456789";

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
	{
		i += put_d(nb / 10);
		i += put_d(nb % 10);
	}
	if (nb < 10)
	{
		i += write(1, &s[nb % 10], 1);
	}
	return (i);
}

int put_x(unsigned int nb)
{
	int i = 0;
	char *s = "0123456789abcdef";

	if (nb >= 16)
	{
		i += put_x(nb / 16);
		i += put_x(nb % 16);
	}
	if (nb < 10)
	{
		i += write(1, &s[nb % 16], 1);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int i = 0;
	int res = 0;
	va_list	ptr;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				res += put_s(va_arg(ptr, char *));
			else if (format[i] == 'd')
				res += put_d(va_arg(ptr, long long));
			else if (format[i] == 'x')
				res += put_x(va_arg(ptr, unsigned int));
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
	char *str = NULL;
	long long nb = -33725623544384;
	unsigned int hex = 100;

	printf("str: %s, int:%lld, hex:%x\n", str, nb, hex);
	ft_printf("str: %s, int:%d, hex:%x\n", str, nb, hex);
	return (0);
}
