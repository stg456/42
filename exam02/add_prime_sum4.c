#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res;

	if (str[i] == '-')
	{
		write(1, "0\n", 1);
		exit(EXIT_FAILURE);
	}
	while (str)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	return (res);
}

int check(int nb)
{
	int i = 2;

	while (nb > i)
	{
		if ((nb % i) == 0)
			return (0);
		i++;	
	}
	return (1);
}

void ft_putnbr(int res)
{
	char c;

	if (res >= 10)
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
	else
	{
		c = res + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	int i = 2;
	int nb;
	int res = 0;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		while (nb >= i)
		{
			if (check(nb) == 1)
				res = res + nb;
			i++;
		}
		ft_putnbr(res);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

// pas encore bon