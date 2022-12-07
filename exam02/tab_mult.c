#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *av)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while ((av[i] >= '\t' && av[i] <= '\r') || av[i] == ' ')
		++i;
	if (av[i] == '+' || av[i] == '-')
	{
		if (av[i] == '-')
			sign *= -1;
		++i;
	}
	while (av[i] >= '0' && av[i] <= '9')
	{
		res = (av[i] - '0') + (res * 10);
		++i;
	}
	return (sign * res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int main(int ac, char **av)
{
	(void)av;
	int i = 1;
	char	j;
	int k = ft_atoi(av[1]);

	if (ac == 2)
	{
		while (i <= 9)
		{
			j = i + '0';
			write(1, &j, 1); // index
			write(1, " x ", 3);
			ft_putnbr(k);
			write(1, " = ", 3);
			ft_putnbr(i * k);
			++i;
			write(1, "\n", 1);
		}
	}
	return (0);
}