/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:01 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/26 11:29:51 by stgerard         ###   ########.fr       */
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

int	ft_pwd(char *buf)
{
	// (void)shell;
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
// le pwd doit pouvoir fonctionner avec des ' ' après, c'est pas le cas.

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