#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int end = 0;
	int start = 0;

	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == ' ' || av[1][i] == '\t' || av[1][i] == '\0')
				i--;
			end = i;
			while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
				i--;
			start = i + 1;
			while (start < end)
			{
				write(1, &av[1][i], 1);
				start++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// pas bon du tout