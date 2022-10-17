#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	if (str[i] == '-')
	{
		write(1, "0\n", 2);
		exit (EXIT_FAILURE);
	}
	while (*str)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	printf("%d\n", res);
	return (res);
}

int check(int nb, int i)
{
	if (nb % i == 0)
		return (1);
	return (0);
}

void ft_putnbr(int res)
{
	// int i = 0;
	char c;

	while (res > 0)
	{
		if (res > '9')
			ft_putnbr(res / 10);
		if (res >= '0' && res <= '9')
		{
			c = res + '0';
			write(1, &c, 1);
		}
	}
}

int main(int ac, char **av)
{
	int nb;
	int i = 2;
	int res = 0;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		printf("%d\n", nb);
		if (check(nb, i) == 1)
		{
			res += i;
		}
		else
			i++;
		ft_putnbr(res);
	}
	else
		write(1, "0\n", 2);
	write(1, "\n", 1);
	return (0);
}

// pas bon