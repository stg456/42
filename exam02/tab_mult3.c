#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	return (res);
}

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
		int i = 0;
		int a = ft_atoi(av[1]);

		while (++i <= 9)
		{
			a = ft_atoi(av[1]);
			// printf("%d \n", a);
			int a = ft_atoi(av[1]);
			ft_putnbr(i);
			write(1, " * ", 3);
			ft_putnbr(a);
			write(1, " = ", 3);
			ft_putnbr(a * i);
			// i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

// bon