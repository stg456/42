#ifndef CAMERA_H
# define CAMERA_H

# include "miniRT.h"

typedef	struct s_cam
{
	t_vec	pos;
	t_vec	forward; // c'est quoi ?
	t_vec	axe; // cette donnee est dans le fichier
	t_vec	up;
	t_vec	right;
	float	h;
	float	w;
	int		fov; // celle là aussi
}	t_cam;

t_cam	*cam_init(t_vec pos, t_vec target, t_vec upguide, int fov, float aspect_ratio);

t_ray	make_ray(t_vec2	point);

#endif
