#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int			i = 0;
	va_list		ptr;
	int 		res = 0;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				res += puts(va_arg(ptr, char *));
			else if (format[i] == 's')
				putd(va_arg(ptr, int));
			else if (format[i] == 's')
				putx(va_arg(ptr, unsigned int));
		}
		else
			;
		i++;
	}
	va_end(ptr);
	return(res);
}

// printf("\033[2K\r");