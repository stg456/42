#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	// int k = 0;
	// char	*s = av[1];

	if (ac == 2)
	{
		while (av[1][i])
		{

		}
	}
	write(1, "\n", 1);
	return (0);

		while (av[1][i])
		{
			if (av[1][i] == '\t' || av[1][i] == ' ')
				i++;
			if (av[1][i] >= 65 && av[1][i] <= 126)
				i++;
			if (av[1][i] == '\t' || av[1][i] == ' ')
				i++;
			while (av[1][i] >= 65 && av[1][i] <= 126)
			{
				write(1, &av[1][i], 1);
				i++;
			}
			i = 0;
			if (av[1][i] == '\t' || av[1][i] == ' ')
				i++;
			if (av[1][i] >= 65 && av[1][i] <= 126)
			{
				while (av[1][i] != '\t' && av[1][i] != ' ')
				{
					s[k] = av[1][i];
					write(1, &s[k], 1);
					i++;
					k++;
				}
			}
			return (0);
		}
	}
}
//pas bon