/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:38:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/05 16:21:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_img(t_env *e, char *path)
{
	char	*apath;
	void	*img;
	int		width;
	int		height;

	apath = ft_strjoin("./sprites/", path);
	img = mlx_xpm_file_to_image(e->mlx, apath, &width, &height);
	if (!img)
		ft_error("\x1B[31mError : invalid file.");
	return (img);
}

void	init_visu(t_env *e)
{
	e->visu.player = xpm_to_img(e, "player.xpm");
	e->visu.collectible = xpm_to_img(e, "collectible.xpm");
	e->visu.floor = xpm_to_img(e, "floor.xpm");
	e->visu.wall = xpm_to_img(e, "wall.xpm");
	e->visu.exit = xpm_to_img(e, "exit.xpm");
	e->visu.exitc = xpm_to_img(e, "exitc.xpm");
}

void	put_mlx(t_env *e, void *img, int x, int y)
{
	mlx_put_image_to_window(e->mlx, e->win, img, x, y);
}

int	build(t_env *e)
{
	t_pos	p;

	ft_printf("x %i y %i\n", e->p_x, e->p_y);
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
				put_mlx(e, e->visu.collectible, p.x * T_S, p.y * T_S);
			else if (e->map[p.y][p.x] == 'E')
				put_mlx(e, e->visu.exit, p.x * T_S, p.y * T_S);
			else if (e->map[p.y][p.x] == 'P')
			{
				e->p_x = p.x;
				e->p_y = p.y;
				put_mlx(e, e->visu.player, p.x * T_S, p.y * T_S);
			}
			++p.x;
		}
		++p.y;
	}
	return (0);
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

int	refresh(t_env *e)
{
	t_pos	p;

	collision_check(e);
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
			{
				if (e->collected == 0)
					put_mlx(e, e->visu.collectible, p.x * T_S, p.y * T_S);
				else
					;
			}
			else if (e->map[p.y][p.x] == 'E')
			{
				if (e->collected == 0)
					put_mlx(e, e->visu.exitc, p.x * T_S, p.y * T_S);
				else
					put_mlx(e, e->visu.exit, p.x * T_S, p.y * T_S);
			}
			++p.x;
		}
		++p.y;
	}
	put_mlx(e, e->visu.player, e->p_x * T_S, e->p_y * T_S);
	return (1);
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
