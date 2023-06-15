#ifndef SPHERE_H
# define SPHERE_H

#include "shape.h"

typedef struct s_sphere
{
	t_vec	pos; // centre
	float	radius;
	t_color	rgb;
}	t_sphere;

t_sphere	*sphere_init(t_vec *pos, float radius);

bool		sphere_intersect(t_sphere *sphere1, t_inter *inter1);
bool		sphere_doesintersect(t_sphere *sphere1, t_ray *ray1);

#endif