#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int start;
	int end;
	// int flag;

	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			start = i;
			// flag = start;
			while (av[1][i] != ' ' && av[1][i] != '\t')
				i++;
			end = i;
			while (av[1][i])
			{
				write(1, &av[1][i], 1);
				i++;
			}
			// if (flag == 1)
			write(1, " ", 1);
			while (start < end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
		}
	}
}

// pas bon manque le flag