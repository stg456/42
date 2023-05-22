/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/22 15:18:44 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

// # define T_S 63

# define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2

typedef struct s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct s_data
{
	int			nbA;
	float		ratioA;
	int			Ar;
	int			Ag;
	int			Ab;
	int			nbC;
	float		cx;
	float		cy
	float		cz;
	float		cxv;
	float		cyv;
	float		czv;
	int			fov;
	int			nbL;
	float		Lx;
	float		Ly;
	float		Lz;
	float		ratioL;
	int			Lr;
	int			Lg
	int			Lb;
	int			nbsp;
	float		spx;
	float		spy;
	float		spz;
	float		spd;
	int			spr;
	int			spg;
	int			spb;
	int			nbpl;
	float		plx;
	float		ply;
	float		plz;
	float		plxv;
	float		plyv;
	float		plzv;
	int			nbcy;
	float		cyx;
	float		cyy;
	float		cyz;
	float		cyxv;
	float		cyyv;
	float		cyzv;
	float		cyd;
	float		cyh;
	int			cyr;
	int			cyg;
	int			cyb;
}				t_data;

// main.c

int		main(int ac, char **av);
void	ft_error(char *str);
int		key_hook(int key, t_env *e);
int		close_hook(t_env *e);

// check.c

void	check(t_env e, int ac, char **av);


#endif