#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_s(char *str)
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
		write(1, '-', 1);
		nb *= -1;
		i++;
	}
	if (nb > 9)
	{
		ft_d(nb / 10);
		ft_d(nb % 10);
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

	if (nb > 16)
	{
		ft_x(nb / 16);
		ft_x(nb % 16);
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
	// int len = 0;
	// char c;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		format++;
		if (*format == '%' && (*format + 1 == 's'))
			ft_s(va_arg(ptr, char *));
		else if (*format == '%' && (*format + 1 == 'd'))
			ft_d(va_arg(ptr, int));
		else if (*format == '%' && (*format + 1 == 'x'))
			ft_x(va_arg(ptr, unsigned int));
		
	}
	va_end(ptr);
	return ();
}

// pas bon