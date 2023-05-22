/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:44:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/22 15:40:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check(t_env e, int ac, char **av)
{
	if (ac != 2)
		ft_error("\x1B[31mError: Bad number of arguments\n");
	if (ft_strnstr(av[1], ".rt", ft_strlen(av[1])) == NULL)
		ft_error("\x1B[31mError: map has to be .rt\n");
}
