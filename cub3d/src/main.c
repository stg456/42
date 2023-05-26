/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/26 15:49:48 by stgerard         ###   ########.fr       */
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
	printf("c'est un beau bordel !\n");
	free(e);
	exit(EXIT_SUCCESS);
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

int	main(int ac, char **av)
{
	t_env	*e;
	(void)ac;
	(void)av;

	e = malloc(sizeof(t_env));
	e->size_x = 640;
	e->size_y = 480;
	e->mlx = mlx_init(e->size_x, e->size_y, "cub3d", false);
	mlx_key_hook(e->mlx, &keyhook, e);
	// e->img = mlx_new_image(e->mlx, e->size_x, e->size_y);
	
	// mlx_image_to_window(e->mlx, e->img, 0, 0);

	mlx_loop(e->mlx);
	close_hook(e);
	return (0);
}