#include "miniRT.h"

bool	shapes_intersect(t_shape *shapes, t_inter *inter)
{
	bool	hit;
	int		i;

	hit = false;
	i = 0;
	while (i < shapes->plane_nb)
	{
		if (hit_pl(inter, &shapes->planes[i]))
			hit = true;
		// printf("pl: %d ", i);
		i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (hit_sp(inter, &shapes->spheres[i]))
			hit = true;
		// printf("sph: %d ", i);
		i++;
	}
	i = 0;
	while (i < shapes->cyl_nb)
	{
			if (hit_cy(inter, &shapes->cylindres[i]))
				hit = true;
			// printf("sph: %d\n", i);
			i++;
	}
	return (hit);
}
