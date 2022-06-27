/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:23:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/21 13:59:49 by stgerard         ###   ########.fr       */
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
	if (key == 'W')
	else if (key == 'A')
	else if (key == 'S')
	else if (key == 'D')
	else if (key == 53)
		close_hook(e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;
	t_map	map;
	(void)argc;

	ft_size_win(&e, argv);
	map.map = ft_calloc(e.size_y+1, sizeof(char *));
	if (!map.map)
	{
		perror("\x1B[31mError\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&e, &map);
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