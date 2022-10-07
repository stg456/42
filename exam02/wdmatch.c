#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
	int i = 0;

	while (*str)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	char *res;

	if (ac == 3)
	{
		while (av[1][i] && av[2][j])
		{
			if (av[1][i] == av[2][j])
			{
				*res = av[1][i];
				i++;
			}
			else
				j++;
		}
		i = 0;
		while (res[i] && av[1][i])
		{
			if (res[i] == av[1][i])
				i++;
			else
			{
				write(1, "\n", 1);
				return (0);
			}
		}
		ft_putstr(res);
	}
	write(1, "\n", 1);
	return (0);
}