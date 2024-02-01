#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int a = 0;
	int b = 0;
	int i = 0;
	// int res;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a > b)
			i = b;
		else
			i = a;
		// printf("a = %d b = %d \n", a, b);
		while (a > 0 && b > 0 && i > 0)
		{
			if ((a % i) == 0 && (b % i) == 0)
			{
				printf("%d \n", i);
				return (i);
			}
			else
				i--;
		}
	}
	printf("\n");
	return (0);
}

// bon