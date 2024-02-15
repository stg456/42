#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fprime(int a)
{
	int i = 2;

	if (a == 1)
		printf("1");
	while (i <= a)
	{
		if (a % i == 0)
		{
			printf("%d", i);
			if (a != i)
				printf("*");
			a = a / i;
			i = 2;
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}