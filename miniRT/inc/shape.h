#ifndef SHAPE_H
# define SHAPE_H

#include "vector.h"
#include "sphere.h"
#include "plane.h"
#include "cylindre.h"
#include "ray.h"
#include "intersection.h"

typedef struct s_shape
{
	t_sphere	**spheres;
	t_plane		**planes;
	t_cyl		**cylindres;

}	t_shape;

bool	shape_intersect(t_shape *shapes, t_inter inter1);
bool	shape_doesintersect(t_shape *shapes, t_ray ray1);

#endif