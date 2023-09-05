/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:25:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 14:54:06 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

	// else if (keydata.key == MLX_KEY_S)
	// 	save_img(d.img, av[1]);

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(d, 0);
	return ;
}

void	expose_hook(void *param)
{
	t_data	*d;

	d = param;
	if (mlx_image_to_window(d->env.mlx, d->img, 0, 0) < 0)
	{
		mlx_close_window(d->env.mlx);
		ft_error("Error\nimpossible to create image\n");
	}
}

void	mlx_loops(t_data *d)
{
	mlx_key_hook(d->env.mlx, &keyhook, &d->env);
	mlx_loop_hook(d->env.mlx, &expose_hook, d);
	mlx_loop(d->env.mlx);
}
