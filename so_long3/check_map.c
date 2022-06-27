/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:59:55 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/23 16:50:13 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'C' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'F'))
			perror("\x1B[31mError : unknown characters in map file.");
			exit(EXIT_FAILURE);
		i++;
	}
}

void	wall_check(t_env *e)
{
	char	*str;

}

// void	min_check(t_env *map)
// {
// 	if (map->p_nb != 1)
// 		perror("\x1B[31mError : map file must contain one player position.");
// 	if (map->c_nb < 1)
// 		ft_printf("\x1B[31mError : map file must contain one collectible.");
// 	if (map->e_nb < 1)
// 		ft_printf("\x1B[31mError : map file must contain one exit.");
// 	if (map->p_nb != 1 || map->c_nb < 1 || map->e_nb < 1)
// 		exit(EXIT_FAILURE);
// }

int	check(t_env *e)
{
	char_check(e);
	wall_check(e);

	return (0);
}