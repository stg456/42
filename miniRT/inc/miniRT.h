/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/23 11:18:13 by stgerard         ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <stdint.h>

# include "color.h"
# include "vector.h"
# include "ray.h"
# include "intersection.h"
# include "cylindre.h"
# include "sphere.h"
# include "plane.h"
# include "shape.h"
# include "camera.h"
# include "image.h"
# include "light.h"
# include "env.h"
# include "data.h"


# define PI 3.14159

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
void	load_data(t_data *d, char **av);
void	memory_alloc(t_data *d);

// amb.c
void	amb(char *buf, t_data *d);

// cam.c
void	cam(char *buf, t_data *d);

// lum.c
void	lum(char *buf, t_data *d);

// spher.c
void	sp(char *buf, t_data *d);

// plan.c
void	pl(char *buf, t_data *d);

// cyl.c
void	cyl(char *buf, t_data *d);

// cmpt.c
t_data	cmpt(t_env e, t_data d, char **av);
void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor);

// utils.c
char	pass(char *str);

#endif