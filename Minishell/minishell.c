/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:47:42 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/12 14:24:39 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_shell(t_minishell *shell)
{
	// t_minishell		*shell;

	close(shell->fd_in);
	close(shell->fd_out);
	free(shell->path);
	free(shell->envdup);
	free(shell);
}

void	ft_init(t_minishell **shell, char **env)
{
	int		i;

	i = 0;
	(*shell) = (t_minishell *)malloc(sizeof(t_minishell));
	while (env[i])
		i++;
	(*shell)->envdup = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (env[i])
	{
		(*shell)->envdup[i] = ft_strdup(env[i]);
		i++;
	}
	(*shell)->envdup = NULL;
	(*shell)->path = NULL;
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 0;
}

void	ft_prompt(char **env)
{
	char			*line;
	t_minishell		*shell;

	line = readline("prompt > ");
	ft_init(&shell, env);
	while (line != NULL)
	{
		if (*line)
		{
			add_history(line);
		}
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// t_minishell		*shell;

	ft_prompt(env);
	
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