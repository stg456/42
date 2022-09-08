#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check(char **av, char *s)
{
	int i = 0;
	int k = 0;

	while (s[k] && av[1][i])
	{
		if (av[1][i] != s[k])
		{
			k++;
		}
		else
			return (0);
	}
	return (1);
}

// pas encore bon

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	char s[] = av[1];
	int k = 0;
	printf("1 %s\n", s);

	if (ac != 3)
	{
		while (av[1][i])
		{
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					(check(*s, *av[1]) = 0)? ;
					s[k] = av[1][i];
					write(1, &av[1][i], 1);
					i++;
					k++;
				}
				else
					j++;
			}
			i++;
		}
	}
	printf("2 %s\n", s);
	write(1, "\n", 1);
	return (0);
}