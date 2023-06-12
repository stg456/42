/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/12 15:47:18 by stgerard         ###   ########.fr       */
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
	int			nbA;
	int			nbC;
	int			nbL;
	int			nbsp;
	int			nbpl;
	int			nbcy;
}				t_data;

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_sp
{
	int			nbsp;
	t_vect		pos;
	double		diam;
	t_color		rgb;
}				t_sp;

typedef struct s_pl
{
	int			nbpl;
	t_vect		pos;
	t_vect		axe;
	t_color		rgb;
}				t_pl;

typedef struct s_cy
{
	int			nbcy;
	t_vect		pos;
	t_vect		axe;
	double		diam;
	double		height;
	t_color		rgb;
}				t_cy;

typedef struct s_amb
{
	int			nbA;
	double		ratioA;
	t_color		rgb;
}				t_amb;

typedef struct s_cam
{
	int			nbC;
	t_vect		pos;
	t_vect		axe;
	int			fov;
}				t_cam;

typedef struct s_lum
{
	int			nbL;
	t_vect		pos;
	double		ratioL;
	t_color		rgb;
}				t_lum;

// main.c

int		main(int ac, char **av);
void	ft_error(char *str);
void	keyhook(mlx_key_data_t keydata, void *param);
int		close_hook(t_env e);

// check.c

void	check(t_env e, int ac, char **av);
int		rgbinrange(int nb);
int		vectinrange(double nb);
int		ratioinrange(double nb);

// init.c

void	init_rt(t_env e, t_data d);

// load.c

int		load_data(t_env e, t_data d, char **av);
t_data	load_data2(char *buf, t_data d);

// parse.c

int		amb(char *buf, t_data d);
int		cam(char *buf, t_data d);
int		lum(char *buf, t_data d);
int		sp(char *buf, t_data d);
int		pl(char *buf, t_data d);
int		cyl(char *buf, t_data d);

// utils.c

char	pass(char *str);

#endif