#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_pgcd(unsigned int a, unsigned int b)
{
	int i = a;
	// int pgcd;

	while (a > 0 && b > 0)
	{
		if ((a % i) == 0 && (b % i) == 0)
		{
			printf("%d", i);
			return ;
		}
		else
			i--;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_pgcd(atoi(av[1]), atoi(av[2]));
	}
	printf("\n");
	return (0);
}

// enfin