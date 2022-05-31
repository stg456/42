/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:13:19 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/31 12:43:47 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int	close_hook(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	e->win = NULL;
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_env *e)
{
	/*if (key == 13 || key == 0 || key == 1 || key == 2)
		move(key, e);*/
	if (key == 53)
		close_hook(e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;
	char	*str;

	(void)argc;

	str = NULL;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "Fdf stgerard");
	mlx_hook(e.win, 17, 0, &close_hook, &e);
	mlx_key_hook(e.win, &key_hook, &e);
	read_map(argv[1]);
	e.img = mlx_new_image(e.mlx, 1000, 1000);
	//mlx_pixel_put(e.mlx, e.win, 0, 0, 0x80808080);
	//mlx_put_image_to_window(e.mlx, e.win, e.img, 10, 10);
	//mlx_string_put(e.mlx, e.win, 50, 50, 0x80808080, argv[1]);

	mlx_loop(e.mlx);
	return (0);
}
