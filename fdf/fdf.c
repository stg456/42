/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:13:19 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/23 16:39:09 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int close_hook(t_env *e)
{
    mlx_destroy_window(e->mlx, e->win);
    e->win = NULL;
    exit(EXIT_SUCCESS);
}

int key_hook(int key, t_env *e)
{
    //if (key == 13 || key == 0 || key == 1 || key == 2)
        //move(key, e);
    if (key == 53)
        close_hook(e);
    return (1);
}

int main(void)
{
	t_env   e;

    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 1000, 1000, "Fdf stgerard");
    mlx_hook(e.win, 17, 0, &close_hook, &e);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_loop(e.mlx);
    readmap(e.win);
	return (0);
}
