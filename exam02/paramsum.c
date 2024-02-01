#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putnbr(int ac)
{
	char nb;

	if (ac > 9)
		ft_putnbr(ac / 10);
	nb = (ac % 10) + '0';
	write(1, &nb, 1);
}

int main(int ac, char **av)
{
	(void)av;

	if (ac >= 2)
	{
		ac--;
		ft_putnbr(ac);
	}
	write(1, "\n", 1);
	return (0);
}