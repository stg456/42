#include "miniRT.h"

bool	shapes_intersect(t_shape *shapes, t_inter *inter)
{
	bool	hit;
	int		i;

	hit = false;
	i = 0;
	while (i < shapes->plane_nb)
	{
		if (plane_intersect(&shapes->planes[i], inter))
			hit = true;
		i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (sphere_intersect(&shapes->spheres[i], inter))
			hit = true;
		i++;
	}
	i = 0;
	while (i < shapes->cyl_nb)
	{
			if (cyl_intersect(&shapes->cylindres[i], inter))
				hit = true;
			i++;
	}
	return (hit);
}

bool	shapes_doesintersect(t_shape *shapes, t_inter *inter)
{
	int		i;

	i = 0;
	while (i < shapes->cyl_nb)
	{
		if (cyl_doesintersect(&shapes->cylindres[i], inter))
			return (true);
		i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (sphere_doesintersect(&shapes->spheres[i], &inter->ray))
			return (true);
		i++;
	}
	i = 0;
	while (i < shapes->plane_nb)
	{
		if (plane_doesintersect(&shapes->planes[i], &inter->ray))
			return (true);
		i++;
	}
	return (false);
}