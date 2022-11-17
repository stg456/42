#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int len(int nbr)
{
	int i = 0;

	while (nbr) // important, pas >= 0
	{
		nbr /= 10;
		i++;
	}
	printf("i = %d \n", i);
	return (i);
}

char	*ft_itoa(int nbr)
{
	int i = len(nbr) - 1;
	char *s;

	s = (char *)malloc(sizeof(char) * (len(nbr) + 1));
	printf("i = %d \n", i);
	while (nbr >= 10)
	{
		s[i] = (nbr % 10) + '0';
		printf("c = %c \n", s[i]);
		nbr /= 10;
		i--;
	}
	if (nbr >= 0)
	{
		s[i] = (nbr % 10) + '0';
		printf("c = %c \n", s[i]);
	}
	printf("s %s\n", s);
	s[len(nbr)] = '\0'; // important le len(nbr)
	return (s);
}

int main(void)
{
	int a = 345;

	ft_itoa(a);
	printf("%s \n", ft_itoa(a));
}

// pas mal