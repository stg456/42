/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:47:42 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/12 11:14:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_minishell **shell, char **envp)
{
	
}

void	ft_prompt(char **envp)
{
	char			*line;
	t_minishell		*shell;

	line = readline("prompt > ");
	ft_init(shell, envp);
	wile (line != NULL)
	{
		if (line)
		{
			add_history(line);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	// path = getenv("PATH");

	ft_prompt(envp);

	// printf("PATH == %s \n", path[j]);
	// path = ft_split(path[j], ':');
	// if (!path[j])
	// 	return (1);
	// while (path[j])
	// {
	// 	printf("%s \n", path[j]);
	// 	j++;
	// }
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