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

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb;

		nb = ft_atoi(av[1]);
		// printf("%d\n", nb);
		if (check(nb) == 1)
		{
			ft_putnbr();
		}
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}