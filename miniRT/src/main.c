/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/05 12:47:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	keyhook(mlx_key_data_t keydata, void* param)
{
	// (void)param;
	t_env	*e;
	e = (t_env *)param;

	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(e);
	// else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
	// 		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
	// 	move(keydata.key, e);
	// else if (keydata.key == MLX_KEY_SPACE)
	// 	action(keydata.key, e);
	return ;
}

int	close_hook(t_env e)
{
	// (void)e;
	free(&e);
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	t_env	e;
	t_data	d;

	// e = malloc(sizeof(t_env));
	// d = malloc(sizeof(t_data));

	e.size_x = 640;
	e.size_y = 480;
	d.i = 0;
	check(e, ac, av);
	load_data(e, d, av);
	
	init_rt(e, d);

	mlx_loop(e.mlx);
	close_hook(e);
	// free(e);
	return 0;
}