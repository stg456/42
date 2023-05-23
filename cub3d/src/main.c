/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/23 11:59:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	close_hook(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	ft_arr_freer(e->map);
	// free(e->visu.player);
	// free(e->visu.collectible);
	// free(e->visu.exit);
	// free(e->visu.exitc);
	// free(e->visu.floor);
	// free(e->visu.pentagram);
	// free(e->visu.enemy);
	// free(e->visu.key);
	// free(e->visu.health);
	free(e->mlx);
	free(e);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_env *e)
{
	if (key == ESC)
		close_hook(e);
	else if (key == W || key == A || key == S || key == D)
		move(key, e);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	*e;

	e = malloc(sizeof(t_env));

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->size_x * T_S, e->size_y * T_S, "Game");
	mlx_hook(e->win, 17, 0, close_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	init_visu(e);
	build(e);
	// mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}