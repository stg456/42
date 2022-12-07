#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int a = atoi(av[1]);
		int c = atoi(av[3]);
		int res = 0;

		if (av[2][0] == '+')
			res = a + c;
		if (av[2][0] == '-')
			res = a - c;
		if (av[2][0] == '*')
			res = a * c;
		if (av[2][0] == '/')
			res = a / c;
		if (av[2][0] == '%')
			res = a % c;
		printf("%d", res);
	}
	write(1, "\n", 1);
	return (0);
}
