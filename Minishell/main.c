/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:11:00 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/11 12:50:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// # include "./libft/libft.h"

int	main(int ac, char **av, char **env)
{
	// (void)env;
	(void)ac;
	(void)av;
	size_t			i;
	char	*s;
	// char	**tab;
	
	i = 0;
	ft_putstr("le prompt>");
	while (env)
	{
		s = ft_strstr(env[1], "PATH=");
		ft_putstr(s);
		// if (env == "PATH=")
		// {
		// 	ft_split("PATH=", ':');
		// }
	}
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
