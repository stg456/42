/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/13 14:31:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;
	e = (t_env *)param;

	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(*e);
	// else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
	// 		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
	// 	move(keydata.key, e);
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
	t_env	e;
	t_data	d;
	t_amb	a;
	(void)ac;
	(void)av;

	// e = malloc(sizeof(t_env));
	// d = malloc(sizeof(t_data));

	e.size_x = 640;
	e.size_y = 480;
	d.nbA = 0;
	e.mlx = mlx_init(e.size_x, e.size_y, "miniRT", false);
	mlx_key_hook(e.mlx, &keyhook, &e);

	load_data(e, d, av);
	printf("main a.rgb.b: %d\n", a.rgb.b);
	// check(e, ac, av);
	
	// init_rt(e, d);

	mlx_loop(e.mlx);
	close_hook(e);
	// free(e);
	return 0;
}