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
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	// printf("%d\n", res);
	return (res);
}

int check(int nb)
{
	int i = 2;

	while (nb > i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb;
		int i = 2;
		int res = 0;

		nb = ft_atoi(av[1]);
		// printf("%d\n", nb);
		while (i <= nb)
		{
			if (check(i))
				res = res + i;
			i++;
		}
		ft_putnbr(res);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

// bon mais pas clair