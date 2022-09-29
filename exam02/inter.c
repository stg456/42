#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check(char *str, char c, int len)
{
	int i = 0;

	while (str[i] && (i < len || len == -1))
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!check(av[1], av[1][i], i) && check(av[2], av[1][i], -1))
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}	
	write(1, "\n", 1);
	return (0);
}

// a revoir