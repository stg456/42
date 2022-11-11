#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len(int nbr)
{
	int i = 0;

	if (nbr < 0)
		++i;
	if (nbr == 0)
		++i;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int i = len(nbr) - 1;
	int	init_len = len(nbr);

	str = malloc(sizeof(char) * len(nbr) + 1);
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	str[init_len] = '\0'; // remettre la len d'origine
	return (str);
}

int main(void)
{
	int nb = 345;

	printf("%s\n", ft_itoa(nb));
}

// bon