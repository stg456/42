#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len(int nbr)
{
	int len = 0;

	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int i = len(nbr) - 1;
	char *str;

	str = malloc(sizeof(char) * (len(nbr) + 1));
	// if (nbr == '0')
	// {
	// 	str[0] = '0';
	// 	return (str);
	// }
	// if (str[0] == '-')
	// {
	// 	str[0] = '-';
	// 	nbr *= -1;
	// }
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
	str[len(nbr)] = '\0';
	return (str); 
}

int main(void)
{
	int nb = 345;

	printf("%s\n", ft_itoa(nb));
}

// pas bon