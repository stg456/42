#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
	int i = 0;
	int j= 0;
	int k = 0;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 10000)))
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		if (!(tab[k] = (char *)malloc(sizeof(char) * 10000)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			tab[k][j++] = str[i];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
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

