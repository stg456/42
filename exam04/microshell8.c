#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int built(char **av)
{
	
}

int main(int ac, char **av, char **env)
{
	int i = 1;

	if (ac == 1)
		return 0;
	av[ac] = 0;
	while (av[i-1] && av[i])
	{
		av = av + i;
		i = 0;
		while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
			i++;
		if (!strcmp(*av, "cd"))
			built(av);
		else 
			exec(av, i, env);
		i++;
	}
}