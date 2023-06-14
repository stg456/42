#include "../../inc/shape.h"

bool	shape_intersect(t_shape *shapes, t_inter inter1)
{
	bool	inter;
	int		i;

	inter = false;
	i = 0;
	while (shapes->cylindres[i] != NULL) // ?
	{
		if (cyl_intersect(shapes->cylindres[i], inter1))
			inter = true;
		i++;
	}
	i = 0;
	while (shapes->spheres[i] != NULL) // ?
	{
		if (sphere_intersect(shapes->spheres[i], inter1))
			inter = true;
		i++;
	}
	i = 0;
	while (shapes->planes[i] != NULL) // ?
	{
		if (plane_intersect(shapes->planes[i], inter1))
			inter = true;
		i++;
	}
	return (inter);
}

bool	shape_doesintersect(t_shape *shapes, t_ray ray1)
{
	int		i;

	i = 0;
	while (shapes->cylindres[i] != NULL) // ?
	{
		if (cyl_doesintersect(shapes->cylindres[i], ray1))
			return (true);
		i++;
	}
	i = 0;
	while (shapes->spheres[i] != NULL) // ?
	{
		if (sphere_doesintersect(shapes->spheres[i], ray1))
			return (true);
		i++;
	}
	i = 0;
	while (shapes->planes[i] != NULL) // ?
	{
		if (plane_doesintersect(shapes->planes[i], ray1))
			return (true);
		i++;
	}
	return (false);
}