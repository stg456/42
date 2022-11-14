#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	char c;

	if (ac == 2)
	{
		if (av[1][i] == '\0' || av[1][i] == '\t' || av[1][i] == ' ')
			i++;
		while (av[1][i])
		{
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				c = av[1][i];
			}
			else if ((av[1][i] == '\t' || av[1][i] == ' '))
			{
				while ((av[1][i] == '\t' || av[1][i] == ' '))
					i++;
				i--;
				c = ' ';
			}
			write(1, &c, 1);
			i++;
		}
	}
	// write(1, "\n", 1);
	return (0);
}

// pas  complétement bon , le dernier ' ' avant le '\0' est toujours là