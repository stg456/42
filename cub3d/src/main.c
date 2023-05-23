/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/23 16:50:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	close_hook(t_env *e)
{
	(void)e;
// 	mlx_destroy_window(e->mlx, e->win);
// 	ft_arr_freer(e->map);
// 	// free(e->visu.player);
// 	// free(e->visu.collectible);
// 	// free(e->visu.exit);
// 	// free(e->visu.exitc);
// 	// free(e->visu.floor);
// 	// free(e->visu.pentagram);
// 	// free(e->visu.enemy);
// 	// free(e->visu.key);
// 	// free(e->visu.health);
// 	free(e->mlx);
	printf("c'est un beau bordel !");
	// free(e);
	exit(EXIT_SUCCESS);
}

// int	key_hook(int key, t_env *e)
// {
// 	if (key == ESC)
// 		close_hook(e);
// 	// else if (key == W || key == A || key == S || key == D)
// 	// 	move(key, e);
// 	return (1);
// }

void	keyhook(t_env *e, mlx_key_data_t keydata, void* param)
{
	(void)param;

	if (keydata.key == ESC)
		close_hook(e);
	return ;
}

int	main(int ac, char **av)
{
	t_env	*e;
	(void)ac;
	(void)av;

	e = malloc(sizeof(t_env));
	e->size_x = 640;
	e->size_y = 480;
	e->mlx = mlx_init(e->size_x, e->size_y, "cub3d", false);
	mlx_key_hook(e->mlx, &keyhook, NULL);
	e->img = mlx_new_image(e->mlx, e->size_x, e->size_y);
	
	mlx_image_to_window(e->mlx, e->img, 0, 0);

	mlx_loop(e->mlx);

	return (0);
}