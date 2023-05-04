#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int g_fd;

int print(char *str)
{
	while (*str)
		write(2, str++, 1);
	return 1;
}

int built(char **av)
{
	if (av[2] && strcmp(av[2], ";") != 0 && strcmp(av[2], "|") != 0)
		return (print("error: cd: bad arguments\n"));
	if (chdir(av[1]) == -1)
		return (print("error: cd: cannot change directory to ") & print(av[1]) & print("\n"));
	return 0;
}

int exe(char **av, int i, char **env)
{
	int fd[2];
	int pid = 0;
	int next = 0;
	if (av[i] && strcmp(av[i], "|") == 0)
		next = 1;
	if (av[i] == *av)
		return 0;
	if (pipe(fd) == -1)
		return (print("error fatal\n"));
	if (pid == -1)
		return (print("error fatal\n"));
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(g_fd, 0);
		av[i] = 0;
		if (next)
			dup2(fd[1], 1);
		if (g_fd != 0)
			close(g_fd);
		close(fd[1]);
		if (execve(*av, av, env) == -1)
		{
			print("error: cannot execute ");
            print(*av);
            print("\n");
            exit (0);
		}
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		if (g_fd != 0)
			close(g_fd);
		if (next)
			g_fd = dup(fd[0]);
		close(fd[0]);
	}
	return 0;
}

int main(int ac, char **av, char **env)
{
	int i = 1;
	if (ac == 1)
		return 0;
	av[ac] = 0;
	while (av[i - 1] && av[i])
	{
		av = av + i;
		i = 0;
		while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
			i++;
		if (!strcmp(av[i], "cd"))
			built(av);
		else
			exe(av, i, env);
		i++;
	}
}

// ./a.out cd ";" /usr/bin/ls ./a.out