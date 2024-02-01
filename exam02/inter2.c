#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int check1(char c, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int check2(char c, char *str, int nb)
{
	int i = 0;

	while (i < nb)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;

	if (ac ==3)
	{
		while (av[1][i])
		{
			if (check1(av[1][i], av[2]) && check2(av[1][i], av[1], i))
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}