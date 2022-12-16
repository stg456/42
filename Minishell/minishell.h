/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:08:23 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/16 15:10:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <stdint.h>
# include <sys/stat.h>
# include <signal.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	char	**envdup;
	char	**path;
	int		fd_in;
	int		fd_out;
}				t_minishell;

// minishell.c

int		main(int ac, char **av, char **env);
void	ft_prompt(char **env);
void	ft_init(t_minishell **shell, char **env);
void	ft_free_shell(t_minishell *shell);

// utils

int		ft_strcmp(char *s1, char *s2);

#endif