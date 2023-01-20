#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
​
void put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}
​
void put_digit(long long int number, int base, int *length)
{
	char *tab = "0123456789abcdef";
​
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &tab[number % base], 1);
}
​
int ft_printf(const char *format, ...)
{
	int len;
	va_list ptr;
​
	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
			{
				put_string(va_arg(ptr, char *), &len);
			}
			else if (*format == 'd')
			{
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			}
			else if (*format =='x')
			{
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
			}
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}
​
int main()
{
	int nbr = -255;
	char txt[5] = "test";
	int tmp = 0;
	char *nulle = NULL;
​
	tmp = printf("%d\n", nbr);
	printf("%d\n", tmp);
	tmp = ft_printf("%d\n", nbr);
	printf("%d\n", tmp);
​
	tmp = printf("%x\n", nbr);
	printf("%d\n", tmp);
	tmp = ft_printf("%x\n", nbr);
	printf("%d\n", tmp);
​
	printf("%s\n", txt);
	ft_printf("%s\n", txt);
	printf("blablabla\n");
	ft_printf("blablabla\n");
​
	tmp = printf("%s\n", nulle);
	printf("%d\n", tmp);
	tmp = ft_printf("%s\n", nulle);
	printf("%d\n", tmp);
	return 0;
}