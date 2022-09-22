#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	char c;

	if (ac > 1)
	{
		while (av)
		{
			if (*av[i] - 1 != ' ' || *av[i] - 1 != '\t' || *av[i] - 1 != '\0')
			{
				
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}