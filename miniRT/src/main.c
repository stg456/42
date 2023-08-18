/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/17 18:34:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_error(char *str/*, t_data d*/)
{
	// close(d.fd);
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(*e);
	// else if (keydata.key == MLX_KEY_S)
	// 	save_img(d.img, av[1]);
	// else if (keydata.key == MLX_KEY_SPACE)
	// 	action(keydata.key, e);
	return ;
}

int	close_hook(t_env e)
{
	(void)e;
	// free(&e);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data		d;
	(void)ac;

	d.env.size_x = 1280;
	d.env.size_y = 720;
	d.env.mlx = mlx_init(d.env.size_x, d.env.size_y, "miniRT", false);
	d.img = mlx_new_image(d.env.mlx, d.env.size_x, d.env.size_y);
	cmpt(&d, av[1]);
	memory_alloc(&d);
	load_data(&d, av[1]);
	// cyl_calc(&d); // additional function in order to calculate the cylinder coordinate system
	if (mlx_image_to_window(d.env.mlx, d.img, 0, 0) < 0)
	{
		mlx_close_window(d.env.mlx);
		ft_error("Error\nimpossible to create image\n");

	}
	mlx_loop_hook(d.env.mlx, &ray_trace, &d);
	mlx_key_hook(d.env.mlx, &keyhook, &d.env);
	mlx_loop(d.env.mlx);
	mlx_delete_image(d.env.mlx, d.img);
	// mlx_terminate(e.mlx);
	close_hook(d.env);
	// free(e);
	return (0);
}
