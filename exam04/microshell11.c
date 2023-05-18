#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
		
		}
		else if (i != 0 && (strcmp(av[i], ";") == 0 || av[i] == NULL))
		{
		
		}
		else if (i != 0 && strcmp(av[i], "|"))
		{
		
		}
	}
	close(tmpfd);
	return 0;
}