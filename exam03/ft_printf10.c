#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	put_str(char *str)
{
	int i = 0;

	// if (str[i] == "NULL")
	// 	return (NULL);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int		put_nb(long long int nb, int base)
{
	int i = 0;
	char *s = "0123456789abcdef";

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= base)
	{
		put_nb((nb / base), base);
		put_nb((nb % base), base);
	}
	if (nb < base)
	{
		write(1, &s[nb], 1);
		i++;
	}
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list	ptr;
	int i = 0;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				put_str(va_arg(ptr, char *));
			if (format[i] == 'd')
				put_nb(va_arg(ptr, int), 10);
			if (format[i] == 'x')
				put_nb(va_arg(ptr, unsigned int), 16);
		}
		i++;
	}
	va_end(ptr);
	return (i);
}

int main(void)
{
	
}