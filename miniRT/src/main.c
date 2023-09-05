/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 10:22:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	d_init(t_data *d, int width, int height)
{
	d->env.size_x = width;
	d->env.size_y = height;
	d->env.mlx = mlx_init(d->env.size_x, d->env.size_y, "miniRT", false);
	d->img = mlx_new_image(d->env.mlx, d->env.size_x, d->env.size_y);
	d->shapes.cylindres = NULL;
	d->shapes.spheres = NULL;
	d->shapes.planes = NULL;
}

int	main(int ac, char **av)
{
	t_data		d;
	(void)ac;

	d_init(&d, 1280, 720);
	load_data(&d, av[1]);
	ray_trace(&d);
	mlx_loops(&d);
	close_hook(&d, 0);
	return (0);
}
