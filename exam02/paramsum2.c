#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putnbr(int nb)
{
	char c;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	(void)av;
	if (ac >= 2)
	{
		ft_putnbr(ac - 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

// bon