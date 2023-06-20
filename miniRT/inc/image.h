#ifndef IMAGE_H
# define IMAGE_H

# include "miniRT.h"

typedef struct s_img
{
	int	width;
	int	height;
	float	*data;
}	t_img;

float	*get_pixel(t_img *img, int x, int y);

void	render(t_img *img, t_data *d); // à adapter

void	save_img(t_img *img, char *filename);

void	ray_trace(t_img *img, t_cam *cam, t_shape *shapes);
#endif