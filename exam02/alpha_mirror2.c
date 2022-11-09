#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	char c;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				c = 'Z' - av[1][i] + 'A';
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				c = 'z' - av[1][i] + 'a';
			else
				c = av[1][i];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// bon