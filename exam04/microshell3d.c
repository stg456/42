#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int ft_error(char *str, char *av)
{
	while (str && *str)
		write(2, str++, 1);
	if (av)
		while (*av)
			write(2, av++, 1);
	write(2, "\n", 1);
	return 1;
}

int ft_exe(char **av, int i, int tmpfd, char **env)
{
	av[i] = NULL;
	dup2(tmpfd, STDIN_FILENO);
	close(tmpfd);
	execve(av[0], av, env);
	return (ft_error("error: cannot execute ", av[0]));
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	int i;
	int tmpfd;
	int fd[2];

	tmpfd = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av[i] = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_error("error: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_exe(av, i, tmpfd, env))
					return 1;
			}
			else
			{
				close(tmpfd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmpfd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exe(av, i, tmpfd, env))
					return 1;
			}
			else
			{
				close(fd[1]);
				close(tmpfd);
				tmpfd = fd[0];
			}
		}
	}
	close(tmpfd);
	return 0;
}