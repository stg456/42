#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	int fd[2];
	int tmpfd;
	int i = 0;
	(void)ac;

	tmpfd = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";" && strcmp(av[i], "|")))
			i++;
		if (strcmp(av[0], "cd" == 0))
		{
			if (i != 2)
				ft_error("error: cd: bad arguments");
			else if (chdir(av[1]) != 0)
				ft_error("error: cd: cannot cgange directory to ");
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";" == 0)))
		{

		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], "|" == 0)))
		{
		
		}
	}
}
