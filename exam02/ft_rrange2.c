#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int step = 1;
	int *res;
	int n = end - start + 1; // nb de valeur

	if (n < 0)
		n = start - end;
	printf("valeur de n = %d\n", n);
	res = malloc(sizeof(int) * n);
	res[i] = end;
	if (end > start)
		step = -1;
	i++;
	if (end < start)
	{
		while (i <= n)
		{
			end += step;
			res[i] = end;
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			end += step;
			res[i] = end;
			i++;
		}
	}
	printf("res [3] %d\n", res[3]);
	return (res);
}

int main ()
{
	int *tab;
	int i = 0;

	tab = ft_rrange(-5, -3);
	while (i < 9)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}