/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:38:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/05 18:36:01 by stgerard         ###   ########.fr       */
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
}
