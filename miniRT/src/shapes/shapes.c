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
		i++;
	}
	i = 0;
	while (i < shapes->sphere_nb)
	{
		if (hit_sp(inter, &shapes->spheres[i]))
			hit = true;
		i++;
	}
	i = 0;
	while (i < shapes->cyl_nb)
	{
			if (hit_cy(inter, &shapes->cylindres[i]))
				hit = true;
			i++;
	}
	return (hit);
}

// bool	shapes_doesintersect(t_shape *shapes, t_inter *inter)
// {
// 	int		i;

// 	i = 0;
// 	while (i < shapes->cyl_nb)
// 	{
// 		if (cyl_doesintersect(&shapes->cylindres[i], inter))
// 			return (true);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < shapes->sphere_nb)
// 	{
// 		if (sphere_doesintersect(&shapes->spheres[i], &inter->ray))
// 			return (true);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < shapes->plane_nb)
// 	{
// 		if (plane_doesintersect(&shapes->planes[i], &inter->ray))
// 			return (true);
// 		i++;
// 	}
// 	printf("tata\n");
// 	return (false);
// }