#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int start;
	int end;

	if (ac >= 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			start = i;
			while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				i++;
			end = i;
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;	
			while (av[1][i])
			{
				if (av[1][i] == ' ' || av[1][i] == '\t')
				{
					while (av[1][i] == ' ' || av[1][i] == '\t')
						i++;
					write(1, " ", 1);
					i--;
				}
				else if (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
					write(1, &av[1][i], 1);
				i++;
			}
			write(1, " ", 1);
			while (start < end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
		}
	}
}

// bon , mais quel bordel