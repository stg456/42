#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// int check(char *str, char c)
// {
// 	int i = 0;

// }

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int z = 0;
	char str[10000];
	str[0] = "a";

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (av[1][i] == av[2][j])
			{
				while (str[z])
				{
					if (str[z] != av[1][i])
					{
						z++;
					}
					else if (str[z] == av[1][i])
					{
					
					}
					str[z] = av[1][i];
				}
			}
		}
	}	
	write(1, "\n", 1);
	return (0);
}

// pas encore bon