#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void rev_wstr(char *str)
{
	int i = 0;
	int start;
	int end;

	while (str[i])
		i++;
	while (str[i] != '\0')
	{
		if (str[i] && (space(str[i]) == 1))
			i--;
		end = i;
		if (str[i] && (space(str[i]) == 0))
			i--;
		start = i;
		while (start <= end)
		{
			write(1, &str[i], 1);
			start++;
		}
		start = i;
		i--;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}

// pas bon