/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:01 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/24 14:46:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_exit(t_minishell *shell)
// {

// }

void	ft_env(t_minishell *shell)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		++i;
	}
}

int	ft_pwd(t_minishell *shell)
{
	(void)shell;

	char buffer[256];
    if (getcwd(buffer, 256) == NULL) 
	{
		perror("Cannot get current working directory path\n");
        // fprintf(stderr, "Cannot get current working directory path\n"); // fprintf pas autorise 
        if (errno == ERANGE) 
		{
        	// fprintf(stderr, "Buffer size is too small.\n"); // fprintf pas autorise
			perror("Buffer size is too small.\n");
        }
        exit(EXIT_FAILURE);
    }
    printf("Current working directory: %s\n", buffer);
    return EXIT_SUCCESS;
}

int		ft_echo(char *buf)
{
	printf("%s\n", buf);
	return EXIT_SUCCESS;
}
