/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:01 by stgerard          #+#    #+#             */
/*   Updated: 2023/02/02 17:00:40 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_exit(t_minishell *shell)
// {

// }

int	ft_env(t_minishell *shell)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		++i;
	}
	return (EXIT_SUCCESS);
}

// parait bon

int	ft_pwd(t_minishell *shell)
{
	(void)shell;
	char buffer[256];

    if (getcwd(buffer, 256) == NULL)
	{
		perror("Cannot get current working directory path\n");
        if (errno == ERANGE)
		{
			perror("Buffer size is too small.\n");
        }
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    return EXIT_SUCCESS;
}

// doit remonter une erreur si il y a un argument en plus !!

int		ft_echo(char *buf)
{
	char	*res;

	if (!buf)
		return (-1);
	res = trimecho(buf);
	printf("%s\n", res);
	return EXIT_SUCCESS;
}

// pas encore le -n
// pas mal mais le trim ne free pas 

int		ft_cd(char **path)
{
	int		i;
	char	*tmp; // 
	char	**env;

	i = 0;

}

int	ft_cd(t_minishell *shell, t_node *lst)
{
	int		i;

	shell->dir = getenv("PWD=");
	// printf("%s\n", shell->dir);
	if ((lst->cmd[0] && !lst->cmd[1]))
	{
		shell->dir = getenv("HOME=");
		chdir(shell->dir);
		// printf("%s\n", shell->dir);
	}
	else if (lst->cmd[0] && lst->cmd[1])
	{
		i = chdir(lst->cmd[1]);
		// printf("arg de cd: %s\n", lst->cmd[1]);
		if (i == 0)
		{
			shell->dir = ft_strjoin(lst->cmd[0], " ");
			shell->dir = ft_strjoin(shell->dir, lst->cmd[1]);
		}
		chdir(shell->dir);
		// printf("%s\n", shell->dir);
	}
	return 0;
}