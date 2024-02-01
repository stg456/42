#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void strcap(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && 'z' >= str[i])
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[i++])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i - 1] == ' ' || \
			str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int ac, char **av)
{
	int n = 1;

	while (n < ac)
	{
		strcap(av[n]);
		n++;
	}
	write(1, "\n", 1);
	return (0);
}

// bon