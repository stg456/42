/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:47:42 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/05 19:30:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_shell(t_minishell *shell)
{
	// t_minishell		*shell;
	close(shell->fd_in);
	close(shell->fd_out);
	// /!\ free un tableau
	free(shell->path);
	free(shell->env);
	free(shell);
}

void	ft_init(t_minishell **shell, char **envp)
{
	int		i;

	i = 0;
	(*shell) = (t_minishell *)malloc(sizeof(t_minishell));
	while (envp[i])
		i++;
	(*shell)->env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (envp[i])
	{
		(*shell)->env[i] = ft_strdup(envp[i]);
		i++;
	}
	(*shell)->env = NULL;
	(*shell)->path = NULL;
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 0;

}

void	ft_prompt(char **envp)
{
	char			*buf;
	t_minishell		*shell;

	buf = readline("minishell $>");
	ft_init(&shell, envp);
	// path = ft_split(getenv("PATH"), ':');
	while (buf != NULL)
	{
		buf = readline("minishell $>");
		if (*buf)
		{
			add_history(buf);
			// malloc auto mais free ????
		}
		// ft_parse(buf, shell);

	}
	// ft_free_shell(shell);
}

int	main(int ac, char **av, char **envp)
{
	// int			i;
	(void)ac;
	(void)av;
	// t_minishell		*shell;

	// i = -1;
	// path = ft_split(getenv("PATH"), ':');
	// while (path[++i])
	// 	path[i] = ft_strjoin(path[i], "/");
	
	ft_prompt(envp);
	
	// ft_free_shell(shell);
}

/*

char *getcwd(char *buf, size_t size);  copie le chemin d'accès absolu du répertoire de travail courant dans la chaîne pointée par buf, qui est de longueur size
int unlink(const char *pathname); unlink() détruit un nom dans le système de fichiers. Si ce nom était le dernier lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé
pid_t fork(void);
int execve(const char *fichier, char *const argv[],
int dup(int oldfd);
int dup2(int oldfd, int newfd)

ft_split(PATH, ':');

while (get_next_line(0, &line) > 0)
{
  parsing
  write(0, "~$ ", 3);
}
*/
// char *my_getenv(char **env, char *elem/*"PATH"*/)