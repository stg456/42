/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:23:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/23 11:04:52 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(t_env *e)
{
	//mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	e->win = NULL;
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_env *e)
{
	if (key == W)
	else if (key == A)
	else if (key == S)
	else if (key == D)
	else if (key == ESC)
		close_hook(e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		perror("Bad number of arguments");
		exit(EXIT_FAILURE);
	}
	e.map = init_map(argv[1], &e);
	
	ft_size_win(&e, argv);
	e.map = ft_calloc(e.size_y+1, sizeof(char *));
	if (!e.map)
	{
		perror("\x1B[31mError\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&e, e.map);
	if (!e.map)
	{
		perror("Error\nThe map is not playable\n");
		exit(EXIT_FAILURE);	
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 500, "so_long");
	mlx_hook(e.win, 17, 0, &close_hook, &e);
	mlx_key_hook(e.win, &key_hook, &e);
	//read_map(argv);

	//mlx_pixel_put(e.mlx, e.win, 0, 0, 0xffffffff);
	//mlx_string_put(e.mlx, e.win, 50, 50, 0xffffffff, line);

	mlx_loop(e.mlx);
	return (0);
}