#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	int i = 0;
	int tmpfd;
	int fd[2];
	(void)ac;

	tmpfd = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_error("error: cd: cannot change directory to ", av[1]);
		}
		else if ((av[i] == NULL || strcmp(av[i], ";") == 0) && i != 0)
		{
			if (fork() == 0)
			{}
			else
			{}
		}
		else if (strcmp(av[i], "|") == 0 && i != 0)
		{

		}
	}
	close(tmpfd);
	return 0;	
}