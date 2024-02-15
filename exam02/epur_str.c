#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void epur(char *str)
{
	int i = 0;

	if (str[i] == ' ' || str[i] == '\t')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		{
			write(1, &str[i], 1);
		}
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0') // le '\0' pour supprimer le ' ' a la fin
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			i--;
			write(1, " ", 1);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		epur(av[1]);
	write(1, "\n", 1);
	return (0);
}

// bon 