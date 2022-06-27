/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:23:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/27 16:08:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	close_hook(t_env *e)
{
	//mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	e->win = NULL;
	exit(EXIT_SUCCESS);
}

// int	key_hook(int key, t_env *e)
// {
// 	if (key == W)
// 	else if (key == A)
// 	else if (key == S)
// 	else if (key == D)
// 	else if (key == ESC)
// 		close_hook(e);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_env	*e;
	
	e = malloc(sizeof(t_env));
	if (argc != 2)
		ft_error("Error\nBad number of arguments\n");
	e->map = init_map(&argv[1], e);
	//e->map = ft_calloc(e->size_y+1, sizeof(char *));
	ft_size_win(e);
	if (!e->map)
		ft_error("Error\nThe map is not playable\n");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->size_x, e->size_y, "so_long");

	//mlx game

	mlx_hook(e->win, 17, 0, close_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	//mlx_loop_hook(e->mlx, loop_hook, e);
	//mlx_put_image_to_window(e->mlx, e->win, e->img, e->p_x, e->p_y);

	mlx_loop(e->mlx);
	return (0);
}