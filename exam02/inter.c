#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void check(char **av)
{

}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (av[1][i] == av[2][j])
			{
				while (av[1][k] < av[1][i])
				{
					if (av[1][i] != av[1][k])
					{
						++k;
					}
				}
				write(1, &av[1][i], 1);
				++j;
			}
			else
				++j;
			++i;
		}
	}	
	write(1, "\n", 1);
	return (0);
}

// pas encore bon