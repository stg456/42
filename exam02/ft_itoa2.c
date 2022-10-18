#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len(nbr)
{
	int i = 0;

	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	// printf("len %d \n", i);
	return (i);
}

char	*ft_itoa(int nbr)
{
	int i = len(nbr) - 1;
	char *str;

	str = malloc(sizeof(char) * (len(nbr) + 1));
	while (nbr >= 10)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	if (nbr >= 0)
	{
		str[i] = (nbr % 10) + '0';
	}
	// printf("s %s\n", str);
	str[len(nbr)] = '\0';
	return (str);
}

int main(void)
{
	int nbr = 345;

	ft_itoa(nbr);
}