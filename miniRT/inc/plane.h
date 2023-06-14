#ifndef PLANE_H
# define PLANE_H

#include "shape.h"

typedef struct s_plane
{
	t_vec	pos;
	t_vec	normal;
}	t_plane;

t_plane	*plane_init(t_vec *pos, t_vec *normal);

bool	plane_intersect(t_plane *plane1, t_inter *inter1);
bool	plane_doesintersect(t_plane *plane1, t_ray *ray1);

#endif