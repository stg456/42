#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac,char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			i++;
		}
		i--;
		while ((av[1][i] == ' ') || (av[1][i] == '\t') || (av[1][i] == '\n'))
			i--;
		printf("1 %d\n", i);
		i--;
		while ((av[1][i] != ' ') || (av[1][i] != '\t') || (av[1][i] != '\n'))
		{
			i--;
		}
		printf("2 %d\n", i);
		while (av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		printf("3 %d\n", i);
	}
	write(1, "\n", 1);
	return (0);
}

// pas encore bon