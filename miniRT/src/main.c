/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/03 17:59:34 by stgerard         ###   ########.fr       */
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
	// t_data	d;
	// char	**av;

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
	t_env		env;
	t_data		d;
	(void)ac;

	env.size_x = 640;
	env.size_y = 480;
	env.mlx = mlx_init(env.size_x, env.size_y, "miniRT", false);
	d.img = mlx_new_image(env.mlx, env.size_x, env.size_y);
	mlx_key_hook(env.mlx, &keyhook, &env);
	d = cmpt(d.env, d, av);
	memory_alloc(&d);
	load_data(&d, av);
	if (mlx_image_to_window(d.env.mlx, d.img, 0, 0) < 0)
	{
		mlx_close_window(d.env.mlx);
		ft_error("Error\nimpossible to create image\n");

	}
	mlx_loop_hook(d.env.mlx, &ray_trace, &d);
	mlx_loop(d.env.mlx);
	mlx_delete_image(env.mlx, d.img);
	// mlx_terminate(e.mlx);
	close_hook(env);
	// free(e);
	return (0);
}
