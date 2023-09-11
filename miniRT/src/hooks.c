/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:25:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/11 11:51:46 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(d, 0);
	return ;
}

void	expose_img(t_data *d)
{
	if (mlx_image_to_window(d->env.mlx, d->img, 0, 0) < 0)
	{
		mlx_close_window(d->env.mlx);
		ft_error("Error\nimpossible to create image\n");
	}
}

void	mlx_loops(t_data *d)
{
	mlx_key_hook(d->env.mlx, &keyhook, &d->env);
	mlx_loop(d->env.mlx);
}
