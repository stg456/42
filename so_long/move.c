/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:58 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/05 18:40:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int key, t_env *e)
{
	t_pos	old;

	old.x = e->p_x;
	old.y = e->p_y;
	if (key == W && e->map[e->p_y - 1][e->p_x] != '1')
		e->p_y--;
	if (key == A && e->map[e->p_y][e->p_x - 1] != '1')
		e->p_x--;
	if (key == S && e->map[e->p_y + 1][e->p_x] != '1')
		e->p_y++;
	if (key == D && e->map[e->p_y][e->p_x + 1] != '1')
		e->p_x++;
	if (old.x != e->p_x || old.y != e->p_y)
	{
		++e->steps;
		ft_printf("Steps : %i\n", e->steps);
	}
}

void	collision_check(t_env *e)
{
	if (e->map[e->p_y][e->p_x] == 'C')
		e->collected = 1;
	if (e->map[e->p_y][e->p_x] == 'E')
	{
		if (e->collected == 1)
		{
			ft_printf("Good Game !\n");
			close_hook(e);
		}
	}
}

void	refresh(t_env *e)
{
	t_pos	p;

	collision_check(e);
	p.y = 0;
	p.x = 0;
	while (e->map[p.y])
	{
		refresh_tiles(e, p);
		refresh_collectible(e, p);
		refresh_exit(e, p);
		refresh_walls(e, p);
		++p.y;
	}
	put_mlx(e, e->visu.player, e->p_x * T_S, e->p_y * T_S);
}

int	loop_hook(t_env *e)
{
	static unsigned int	frame;

	if (!(++frame % 500))
	{
		refresh(e);
	}
	return (0);
}

void	put_mlx(t_env *e, void *img, int x, int y)
{
	mlx_put_image_to_window(e->mlx, e->win, img, x, y);
}
