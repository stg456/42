#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	char	*s = "0123456789";
	int 	i = 0;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, '-', 1);
		i++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_puthex(nb / 10);
		i += ft_puthex(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int nb)
{
	char	*s = "0123456789abcdef";

	int i = 0;
	if (nb >= 16)
	{
		i += ft_puthex(nb / 16);
		i += ft_puthex(nb % 16);
	}
	if (nb < 16)
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}

int ft_printf(const char *format, ... )
{
	int i = 0;
	int len = 0;
	va_list	ptr;

	va_start (ptr, format);
	while (format[i])
	{
		if ((format[i] == '%') && (format[i + 1]))
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr(va_arg(ptr, char *));
			else if (format[i] == 'd')
				len += ft_putnbr(va_arg(ptr, int));
			else if (format[i] == 'x')
				len += ft_puthex(va_arg(ptr, unsigned int));
		}
		else
		{
			len += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ptr);
	return (len);
}