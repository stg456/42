#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int n = 1;

	if (ac >= 2)
	{
		while (av[n][i])
		{
			if (av[n][i] != ' ' && av[n][i] != '\t' && av[n][i] != '\0')
			{
				
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}