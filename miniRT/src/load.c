/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/07 14:55:30 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	load_data(t_env e, t_data d, char **av)
{
	int	fd;
	(void)e;
	(void)d;


	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("\x1B[31mInvalid file\n");
	}

	

	close(fd);
	return 0;
}