#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int res)
{
	if (res >= 10)
		ft_putnbr(res / 10);
	ft_putchar(res % 10 + '0');	
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 1;
		int a = av[1][0];
		int res = 0;
		char ii = i + '0';
		char aa = a + '0';

		while (i++ <= 9)
		{
			res = a * i;
		}
		write(1, &ii, 1);
		write(1, " * ", 3);
		write(1, &aa, 1);
		write(1, " = ", 1);
		ft_putnbr(res);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}

// pas bon