#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	// pirntf("");
	return (res);
}

void	print_hex(int nb)
{
	char s[] = "0123456789abcdef";

	if (nb >= 16)
		print_hex(nb / 16);
	write(1, &s[nb % 16], 1); // pas besoin du + '0'
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		print_hex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}

// bon