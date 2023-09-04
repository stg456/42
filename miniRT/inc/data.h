#ifndef DATA_H
# define DATA_H

typedef struct	s_data
{
	int			fd;
	mlx_image_t	*img;
	t_cam		cam;
	t_shape		shapes;
	t_amb		amb;
	t_lum		lum;
	t_env		env;
}				t_data;

#endif