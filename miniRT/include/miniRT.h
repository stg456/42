/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/05 12:22:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define PI 3.14159

typedef struct s_env
{
	void	*mlx;
	void	*win;
	size_t	size_x;
	size_t	size_y;
}				t_env;

typedef struct s_data
{
	int			fd;
	char		*buf;
	int			i;
	int			nbA;
	float		ratioA;
	int			Ar;
	int			Ag;
	int			Ab;
	int			nbC;
	float		cx;
	float		cy;
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
	int			Lg;
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
void	key_hook(int key, t_env *e);
int		close_hook(t_env *e);

// check.c

void	check(t_env e, int ac, char **av);
int		rgbinrange(int nb);
int		vectinrange(float nb);
int		ratioinrange(float nb);

// init.c

void	init_rt(t_env e, t_data d);

// load.c

int	load_data(t_env e, t_data d, char **av);

// utils.c


#endif