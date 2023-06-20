/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/20 12:09:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
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

# include "vector.h"
# include "intersection.h"
# include "ray.h"
# include "shape.h"
# include "cylindre.h"
# include "plane.h"
# include "sphere.h"
# include "camera.h"



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
	int			nbA;
	int			nbC;
	int			nbL;
	int			nbsp;
	int			nbpl;
	int			nbcy;
}				t_data;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_amb
{
	int			nbA;
	double		ratioA;
	t_color		rgb;
}				t_amb;

typedef struct s_lum
{
	int			nbL;
	t_vec		pos;
	double		ratioL;
	t_color		rgb;
}				t_lum;

// main.c
int		main(int ac, char **av);
void	ft_error(char *str/*, t_data d*/);
void	keyhook(mlx_key_data_t keydata, void *param);
int		close_hook(t_env e);

// check.c
int		rgbinrange(int nb);
int		vectinrange(double nb);
int		ratioinrange(double nb);
int		fovinrange(int nb);

// init.c
void	init_rt(t_env e, t_data d);

// load.c
t_data	load_data(t_env e, t_data d, char **av);
t_data	load_data2(char *buf, t_data d);

// amb.c
void	amb(char *buf, t_data d);

// cam.c
void	cam(char *buf, t_data d);

// lum.c
void	lum(char *buf, t_data d);

// spher.c
void	sp(char *buf, t_data d);

// plan.c
void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor);
void	pl(char *buf, t_data d);

// cyl.c
void	cyl(char *buf, t_data d);

// cmpt.c
t_data	cmpt(t_env e, t_data d, char **av);

// utils.c
char	pass(char *str);

#endif