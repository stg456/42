/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/16 17:34:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (ac != 2)
		ft_error("\x1B[31mError: Bad number of arguments\n");
	verif(e);



	free(e);
	return 0;
}