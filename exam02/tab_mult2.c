#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	printf("le atoi %d", res);
	return (res);
}

void putnbr(int nb)
{
	if (nb > 9)
		putnbr(nb / 10);
	putnbr(nb % 10 + '0');
}

void tm(int b)
{
	int a = 1;
	int res = 0;
	char aa = a + '0';
	char bb = b + '0';

	while (a <= 9)
	{
		write(1, &aa, 1);
		write(1, " x ", 3);
		write(1, &bb, 1);
		write(1, " = ", 3);
		res = a * b;
		printf("avant le putnbr %d", res);
		putnbr(res);
		write(1, "\n", 1);
		a++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		tm(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}

// pas bon