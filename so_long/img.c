/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:38:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/04 17:10:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_img(t_env *e, char *path)// addition 2 string
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
}

int	build(t_env *e)
{
	e->size_x = 0;
	e->size_y = 0;
	e->p_x = 1;
	e->p_y = 1;
	while (e->map)
	{
		if (e->map[e->p_y][e->p_x] == '1')
		{
			mlx_put_image_to_window(e->mlx, e->win, e->visu.wall,
			e->p_x * IMG_W, e->p_y * IMG_H);
		}
		else if (e->map[e->p_y][e->p_x] != '1')
		{
			mlx_put_image_to_window(e->mlx, e->win, e->visu.floor,
			e->p_x * IMG_W, e->p_y * IMG_H);
		}
		else if (e->map[e->p_y][e->p_x] == 'C')
		{
			mlx_put_image_to_window(e->mlx, e->win, e->visu.collectible,
			e->p_x * IMG_W, e->p_y * IMG_H);
		}
		else if (e->map[e->p_y][e->p_x] == 'E')
		{
			mlx_put_image_to_window(e->mlx, e->win, e->visu.exit,
			e->p_x * IMG_W, e->p_y * IMG_H);
		}
		else if (e->map[e->p_y][e->p_x] == 'P')
		{
			mlx_put_image_to_window(e->mlx, e->win, e->visu.player,
			e->p_x * IMG_W, e->p_y * IMG_H);
		}
		e->p_x++;
	}
	return (0);
}
