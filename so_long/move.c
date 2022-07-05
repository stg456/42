/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:58 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/05 16:06:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int key, t_env *e)
{
	if (key == W && e->map[e->p_y - 1][e->p_x] != '1')
		e->p_y--;
	if (key == A && e->map[e->p_y][e->p_x - 1] != '1')
		e->p_x--;
	if (key == S && e->map[e->p_y + 1][e->p_x] != '1')
		e->p_y++;
	if (key == D && e->map[e->p_y][e->p_x + 1] != '1')
		e->p_x++;
}
