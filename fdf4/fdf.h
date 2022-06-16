/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:38:57 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 15:45:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	struct s_cam	*cam;
	struct s_m3		*p;
	struct s_m3		*d2;
	int				width;
	int				height;
	int				min_z;
	int				max_z;
	int				max_y;
	int				max_x;
	int				space;
	char			ocean;
	struct s_color	*color_min;
	struct s_color	*color_max;
}					t_env;

typedef struct		s_m3
{
	double			x;
	double			y;
	double			z;
	struct s_m3		*next;
	char			end;
}					t_m3;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color;

typedef struct		s_cam
{
	double			x;
	double			y;
	double			z;
	double			rx;
	double			ry;
	double			rz;
	double			fov;
}					t_cam;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				read_point(char **line, t_env *e, int *x, int y);
int					open_file(t_env *e, char *file);
int					read_file(int fd, t_env *e);
t_m3				*calculate_point(t_m3 *p, t_cam *c, t_env *e);
void				info(t_env *e);
void				info_cam(t_env *e);
void				info_max_min(t_env *e);
t_color				*init_color(int r, int g, int b, int a);
void				init_first_cam(t_env *e);
void				put_pixel(int x, int y, t_env *e);
void				put_pixel_color(int x, int y, t_env *e, t_color *r);
unsigned int		convert_color(t_color *color);
t_color				*get_color(t_env *e, double z);
char				set_color(char *s, t_env *e);
char				is_inside(int x, int y, t_env *e);
void				draw(t_env *e);
void				clear(t_env *e);
void				new_point(int x, int y, double z, t_env *e);
void				drawline(t_m3 *a, t_m3 *b, t_env *e);
void				end_point(t_env *e);
t_m3				*new_m3(int x, int y, int z, char end);
t_cam				*init_cam(void);
t_env				*init_env(void);
void				ft_close(t_env *e);

#endif