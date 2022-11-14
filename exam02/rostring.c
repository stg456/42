#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void rostring(char *str)
{
	int i = 0;
	int start;
	int end;

	while (str[i] && check_space(str[i]) == 1)
		i++;
	start = i;
	while (str[i] && check_space(str[i]) == 0)
		i++;
	end = i;
	while (str[i] && check_space(str[i]) == 1)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] && check_space(str[i]) == 0)
		{
			write(1, &str[i], 1);
		}
		else if (str[i] && check_space(str[i]) == 1)
		{
			while (str[i] && check_space(str[i]) == 1)
			{
				i++;
			}
			i--;
			write(1, " ", 1);
		}
		i++;
	}
	write(1, " ", 1);
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int main(int ac, char **av)
{
	if (ac> 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
// pas bon, pb de ' '