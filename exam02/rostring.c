#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int i2;
	int i3;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (!(av[1][i] >= 65 && av[1][i] <= 126))
				i++;
			i2 = i;
			if (av[1][i] && (av[1][i] >= 65 && av[1][i] <= 126))
				i++;
			i3 = i;
			while (!(av[1][i] >= 65 && av[1][i] <= 126))
				i++;
		}
		printf("%d\n", i);
		printf("%d\n", i2);
		printf("%d\n", i3);
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 65 && av[1][i] <= 126)
			{
				write(1, &av[1][i], 1);
				i++;
			}
			else if (!(av[1][i] >= 65 && av[1][i] <= 126))
			{
				write(1, " ", 1);
				i++;
			}
		}
		// i = i2;
		// while (i2 < i3)
		// {
		// 	write(1, &av[1][i], 1);
		// 	i2++;
		// }
	}
	write(1, "\n", 1);
	return (0);
}
//pas bon