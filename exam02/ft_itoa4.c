#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len(int nbr)
{
	int len = 0;

	while (nbr)
	{
		nbr = nbr / 10;
		len += 1;
	}
	// printf("len %d \n", len);
	return (len);
}

char	*ft_itoa(int nbr)
{
	int i = len(nbr) - 1;
	char *s;

	s = (char *)malloc(sizeof(char) * (len(nbr) + 1));

	while (nbr >= 10)
	{
		s[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	if (nbr >= 0)
	{
		s[i] = (nbr % 10) + '0';
	}
	s[len(nbr)] = '\0';
	printf("%s \n", s);
	return (s); 
}

int main(void)
{
	int nbr = 345;

	ft_itoa(nbr);
}

// pas bon