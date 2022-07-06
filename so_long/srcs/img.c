/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:38:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/06 16:56:37 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	build_player(t_env *e, t_pos p)
{
	e->p_x = p.x;
	e->p_y = p.y;
	put_mlx(e, e->visu.player, p.x * T_S, p.y * T_S);
}

void	init_visu(t_env *e)
{
	e->visu.player = xpm_to_img(e, "player.xpm");
	e->visu.floor = xpm_to_img(e, "floor.xpm");
	e->visu.wall = xpm_to_img(e, "wall.xpm");
	e->visu.exit = xpm_to_img(e, "exit.xpm");
	e->visu.exitc = xpm_to_img(e, "exitc.xpm");
	e->visu.enemy = xpm_to_img(e, "enemy.xpm");
	img_to_sprite(e, &e->visu.health, "health", 3);
	img_to_sprite(e, &e->visu.key, "key", 9);
	e->visu.health->head = e->visu.health;
}

void	build(t_env *e)
{
	t_pos	p;

	p.y = 0;
	while (e->map[p.y])
	{
		p.x = 0;
		while (e->map[p.y][p.x])
		{
			put_mlx(e, e->visu.floor, p.x * T_S, p.y * T_S);
			if (e->map[p.y][p.x] == '1')
				put_mlx(e, e->visu.wall, p.x * T_S, p.y * T_S);
			else if (e->map[p.y][p.x] == 'C')
				put_mlx(e, e->visu.key->img, p.x * T_S, p.y * T_S);
			else if (e->map[p.y][p.x] == 'E')
				put_mlx(e, e->visu.exitc, p.x * T_S, p.y * T_S);
			else if (e->map[p.y][p.x] == 'P')
				build_player(e, p);
			else if (e->map[p.y][p.x] == 'X')
				put_mlx(e, e->visu.enemy, p.x * T_S, p.y * T_S);
			++p.x;
		}
		++p.y;
	}
	mlx_string_put(e->mlx, e->win, 0, 20, 0xFFFFFFFF, ft_itoa(e->steps));
}
