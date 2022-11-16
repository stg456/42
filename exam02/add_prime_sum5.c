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
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "0\n", 2);
	}
	else
	{
		ft_atoi(add_prime_sum(av[1]));
		write(1, "\n", 1);
		return (0);
	}
}