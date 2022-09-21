#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 2;
	int res = 0;

	if (ac == 2 && ac >= 0)
	{
		while (i < av[1])
		{
			if (av[1] % i == 0)
			{
				res *= i;
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

// pa encore bon