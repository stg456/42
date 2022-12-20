#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	putchar(char c)
{
	write(1, &c,1);
}

void	putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list	ptr;

	va_start (ptr, format);
	while ()
	{
	
	}
}