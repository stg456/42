#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_num_w(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
			i++;
		else
		{
			while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

int lenmot(char *str, int i)
{
	int res = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		i++;
		res++;
	}
	return (res);
}

char    **ft_split(char *str)
{
	char **tab;
	int	i = 0; // index str
	int j = 0; // index tab[j][k]
	int k = 0;
	int len_w = 0;
	int num_w = 0;

	num_w = ft_num_w(str);
	tab = malloc(sizeof(char *) * num_w + 1);
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i] != '\0')
			i++;
		else
		{
			while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i] != '\0')
			{
				k = 0;
				len_w = lenmot(str, i);
				tab[j] = malloc(sizeof(char) * len_w + 1);
				if (!tab)
				{
					if (j > 0)
					{
						while (j >= 0)
						{
							free(tab[j]);
							j--;
						}
					}
					return (NULL);
				}
				while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i] != '\0')
				{
					tab[j][k] = str[i];
					k++;
					i++;
				}
				tab[j][k] = '\0';
				j++;
			}
		}
	}
	tab[j] = NULL;
	return (tab);
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