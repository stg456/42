/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/07 11:41:19 by stgerard         ###   ########.fr       */
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
	double		ratioA;
	int			Ar;
	int			Ag;
	int			Ab;
	int			nbC;
	double		cx;
	double		cy;
	double		cz;
	double		cxv;
	double		cyv;
	double		czv;
	int			fov;
	int			nbL;
	double		Lx;
	double		Ly;
	double		Lz;
	double		ratioL;
	int			Lr;
	int			Lg;
	int			Lb;
	int			nbsp;
	double		spx;
	double		spy;
	double		spz;
	double		spd;
	int			spr;
	int			spg;
	int			spb;
	int			nbpl;
	double		plx;
	double		ply;
	double		plz;
	double		plxv;
	double		plyv;
	double		plzv;
	int			nbcy;
	double		cyx;
	double		cyy;
	double		cyz;
	double		cyxv;
	double		cyyv;
	double		cyzv;
	double		cyd;
	double		cyh;
	int			cyr;
	int			cyg;
	int			cyb;
}				t_data;

// typedef struct s_sp
// {

// }				t_sp;

// main.c

int		main(int ac, char **av);
void	ft_error(char *str);
void	key_hook(int key, t_env e);
int		close_hook(t_env e);

// check.c

void	check(t_env e, int ac, char **av);
int		rgbinrange(int nb);
int		vectinrange(double nb);
int		ratioinrange(double nb);

// init.c

void	init_rt(t_env e, t_data d);

// load.c

int	load_data(t_env e, t_data d, char **av);

// utils.c


#endif