/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:28:58 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/06 16:15:32 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collision_check(t_env *e)
{
	if (e->map[e->p_y][e->p_x] == 'C')
	{
		if (e->collectible != 0)
			e->collectible--;
	}
	if (e->map[e->p_y][e->p_x] == 'X')
	{
		e->health--;
		ft_printf("Aie !\n");
		if (e->health == 0)
		{
			ft_printf("You lose !\n");
			close_hook(e);
		}
	}
	if (e->map[e->p_y][e->p_x] == 'E')
	{
		if (e->collectible == 0)
		{
			ft_printf("Good Game !\n");
			close_hook(e);
		}
	}
}

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
		++e->steps;
	collision_check(e);
}

void	refresh(t_env *e)
{
	int		i;
	t_pos	p;

	i = 4;
	p.y = 0;
	p.x = 0;
	while (e->map[p.y])
	{
		refresh_tiles(e, p);
		refresh_collectible(e, p);
		refresh_exit(e, p);
		refresh_walls(e, p);
		refresh_enemy(e, p);
		++p.y;
	}
	put_mlx(e, e->visu.player, e->p_x * T_S, e->p_y * T_S);
	mlx_string_put(e->mlx, e->win, 0, 20, 0xFFFFFFFF, ft_itoa(e->steps));
	while (--i > 0)
	{
		if (e->health == i)
			put_mlx(e, e->visu.health->img, 0, 0);
		e->visu.health = e->visu.health->next;
	}
	while (e->visu.health != e->visu.health->head)
		e->visu.health = e->visu.health->next;
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
