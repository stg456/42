#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putnbr(int ac)
{
	char c;
	while (ac > 9)
		ft_putnbr(ac / 10);
	
	if (ac >= 0 && ac <= 9)
	{
		c = ac + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	(void)av;
	ac--;

	if (ac >= 2)
		ft_putnbr(ac);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

// bon