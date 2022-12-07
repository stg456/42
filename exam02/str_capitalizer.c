#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void str_cap(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	i++;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || \
		str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &(str[i]), 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;

	if (ac > 1)
	{
		while (i < ac)
		{
			str_cap(av[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
// enfin presque 
// manque l'espace entre les mots