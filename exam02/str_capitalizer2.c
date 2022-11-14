#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void strcap(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (space(str[i]) == 0 && str[i - 1] == '\0')
		{
			str[i] -= 32;
			write(1, &str[i], 1);
			i++;
		}
		else if (space(str[i]) == 0 && str[i - 1] != '\0')
	}
}

int main(int ac, char **av)
{
	int i = 0;
	int n = 1;

	if (ac >= 2)
		strcap(av[1]);
	write(1, "\n", 1);
	return (0);
}