#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int countword(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' ||str[i] == '\t')
		{
			if ()
			++i;
		}
		++i;
	}
	return (nb);
}

int len(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		i++;
	}
	return (len);
}

char    **ft_split(char *str)
{
	int i = 0;
	char	**tab;

	tab = malloc(sizeof(char *) * (len(str) + 1));
	while (str)
	{

	}
}