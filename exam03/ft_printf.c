#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putstr2(char *str, int *len)
{
	if (!str)
		str = "(NULL)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_putdigit(long long int nb, int base, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, '-', 1);
	}
	if (nb >= base)
	{
		ft_putdigit((nb / base), base, len);
	}
	*len += write(1, &hex[nb % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ptr;
	
	va_start (ptr, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr();
			else if (*format == 'd')
				;
			else if (*format == 'x')
				;
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}