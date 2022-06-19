/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:23:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/19 19:06:38 by stgerard         ###   ########.fr       */
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
	if (key == 'W' || key == 'A' || key == 'S'|| key == 'D')
		key_move(e);//
	if (key == 53)
		close_hook(e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;
	char	*str;
	(void)argc;
	//(void)argv;

	str = NULL;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 500, "so_long stgerard");
	mlx_hook(e.win, 17, 0, &close_hook, &e);
	mlx_key_hook(e.win, &key_hook, &e);
	read_map(argv);

	//mlx_pixel_put(e.mlx, e.win, 0, 0, 0xffffffff);
	//mlx_string_put(e.mlx, e.win, 50, 50, 0xffffffff, line);

	mlx_loop(e.mlx);
	return (0);
}