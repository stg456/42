/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:23:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/04 16:52:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	close_hook(t_env *e)
{
	//mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	e->win = NULL;
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_env *e)
{
	if (key == ESC)
		close_hook(e);
	// else if (key == W)
	// else if (key == A)
	// else if (key == S)
	// else if (key == D)

	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (argc != 2)
		ft_error("\x1B[31mError: Bad number of arguments\n");
	e->map = init_map(argv, e);
	if (!e->map)
		ft_error("\x1B[31mError: The map is not playable\n");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->size_x * 64, e->size_y * 64, "so_long");

	//mlx game

	mlx_hook(e->win, 17, 0, close_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	init_visu(e);
	build(e);
	// mlx_put_image_to_window(e->mlx, e->win, e->visu.player, 0, 0);
	// mlx_put_image_to_window(e->mlx, e->win, e->visu.collectible, 100, 0);
	// mlx_put_image_to_window(e->mlx, e->win, e->visu.floor, 200, 0);
	// mlx_put_image_to_window(e->mlx, e->win, e->visu.wall, 300, 0);
	// mlx_put_image_to_window(e->mlx, e->win, e->visu.exit, 400, 0);

	//mlx_loop_hook(e->mlx, loop_hook, e);

	
	mlx_loop(e->mlx);
	return (0);
}
