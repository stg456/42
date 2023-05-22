/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:10:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/22 15:40:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	key_hook(int key, t_env *e)
{
	if (key == ESC)
		close_hook(e);
	// else if (key == W || key == A || key == S || key == D)
	// 	move(key, e);
	return (1);
}

int	close_hook(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);


	free(e->mlx);
	free(e);
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	t_env	e;
	t_data	d;

	// e = malloc(sizeof(t_env));
	// d = malloc(sizeof(t_data));

	check(e, ac, av);
	load_data(e, av);
	
	init_rt(e);

	// e->mlx = init_map(av, e);
	// if (!e->map)
	// 	ft_error("\x1B[31mError: The map is not playable\n");
	// e->mlx = mlx_init();
	// e->win = mlx_new_window(e->mlx, e->size_x * T_S, e->size_y * T_S, "Game");
	// mlx_hook(e->win, 17, 0, close_hook, e);
	// mlx_key_hook(e->win, key_hook, e);
	// init_visu(e);
	// build(e);
	// mlx_loop_hook(e.mlx, loop_hook, e);
	// mlx_loop(e->mlx);


	// free(e);
	return 0;
}