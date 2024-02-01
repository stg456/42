/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:32:31 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/06 17:49:25 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	refresh_tiles(t_env *e, t_pos p)
{
	while (e->map[p.y][p.x])
	{
		put_mlx(e, e->visu.floor, p.x * T_S, p.y * T_S);
		++p.x;
	}
}

void	refresh_collectible(t_env *e, t_pos p)
{
	while (e->map[p.y][p.x])
	{
		if (e->map[p.y][p.x] == 'C')
		{
			put_mlx(e, e->visu.pentagram, p.x * T_S, p.y * T_S);
			if (e->collectible != 0)
			{
				put_mlx(e, e->visu.key->img, p.x * T_S, p.y * T_S);
				e->visu.key = e->visu.key->next;
			}
		}
		++p.x;
	}
}

void	refresh_exit(t_env *e, t_pos p)
{
	while (e->map[p.y][p.x])
	{
		if (e->map[p.y][p.x] == 'E')
		{
			if (e->collectible == 0)
				put_mlx(e, e->visu.exit, p.x * T_S, p.y * T_S);
			else
				put_mlx(e, e->visu.exitc, p.x * T_S, p.y * T_S);
		}
		++p.x;
	}
}

void	refresh_walls(t_env *e, t_pos p)
{
	while (e->map[p.y][p.x])
	{
		if (e->map[p.y][p.x] == '1')
			put_mlx(e, e->visu.wall, p.x * T_S, p.y * T_S);
		++p.x;
	}
}

void	refresh_enemy(t_env *e, t_pos p)
{
	while (e->map[p.y][p.x])
	{
		if (e->map[p.y][p.x] == 'X')
			put_mlx(e, e->visu.enemy, p.x * T_S, p.y * T_S);
		++p.x;
	}
}
