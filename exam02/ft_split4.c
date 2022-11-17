#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len_tot(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int len_mot(char *str)
{
	int i = 0;

	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char    **ft_split(char *str)
{
	char **tab;
	int i = 0; // index str
	int j = 0; // index tab[j][k]
	int k = 0;

	tab = malloc(sizeof(char) * (len_tot(str) + 1));
	// if (!(tab = (char **)malloc(sizeof(char *) * 256)))
	// 	return (NULL);
	// while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	// 	i++;
	while (str[i])
	{
		k = 0; 
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			tab[j] = malloc(sizeof(char) * (len_mot(str) + 1));
			// if (!(tab[j] = (char *)malloc(sizeof(char) * 4096)))
			// 	return (NULL);
			tab[j][k] = str[i];
			k++;
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	main(void)
{
	int		idx;
	char	**tab;
	idx = 0;
	tab = ft_split("The prophecy is true");
	while (idx < 4)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	return (0);
}

// pas bon n'affiche pas