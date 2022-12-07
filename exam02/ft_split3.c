#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int lentot(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	printf(" len str %d \n", i);
	return (i);
}

int lenmot(char str, int i)
{
	int res = 0;

	while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
	{
		i++;
		res++;
	}
	printf("len mot %d \n", i);
	return (res);
}

char    **ft_split(char *str)
{
	int i = 0; // index str
	int j = 0; // index tab[j][k]
	int k = 0;
	char **tab;

	tab = malloc(sizeof(char) * lentot(str) + 1);
	while (str[i])
	{
		if (str[i] != '\0' && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
			i++;
		else if ((str[i] != '\n' || str[i] != ' ' || str[i] != '\t') && str[i] != '\0')
		{
			tab[j] = malloc(sizeof(char) * lenmot(str, i) + 1);
			tab[j][k] = str[i];
			k++;
			i++;
		}
		else if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		{
			j++;
			i++;
		}

	}
}

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	char **tab;

	tab = ft_split(av[1]);
	while (tab[i])
	{
		printf("%s\n", tab[i]); 
		i++;
	}
	return (0);
}