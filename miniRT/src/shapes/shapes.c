#include "miniRT.h"

bool	shapes_intersect(t_shape *shapes, t_inter *inter1)
{
	bool	inter;
	int		i;

	inter = false;
	i = 0;
	while (i < shapes->cyl_nb)
	{
			if (cyl_intersect(&shapes->cylindres[i], inter1))
				inter = true;
			i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (sphere_intersect(&shapes->spheres[i], inter1))
			inter = true;
		i++;
	}
	i = 0;
	while (i < shapes->plane_nb)
	{
		if (plane_intersect(&shapes->planes[i], inter1))
			inter = true;
		i++;
	}
	return (inter);
}

bool	shapes_doesintersect(t_shape *shapes, t_ray *ray1)
{
	int		i;

	i = 0;
	while (i < shapes->cyl_nb)
	{
		if (cyl_doesintersect(&shapes->cylindres[i], ray1))
			return (true);
		i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (sphere_doesintersect(&shapes->spheres[i], ray1))
			return (true);
		i++;
	}
	i = 0;
	while (i < shapes->plane_nb)
	{
		if (plane_doesintersect(&shapes->planes[i], ray1))
			return (true);
		i++;
	}
	return (false);
}