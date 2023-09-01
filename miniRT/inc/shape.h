#ifndef SHAPE_H
# define SHAPE_H

typedef struct	s_shape
{
	int			sphere_nb; // we shouldnt have the shape count in this struct AND the data struct, needs to be adjusted
	int			plane_nb;
	int			cyl_nb;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cyl		*cylindres;

}				t_shape;

bool	shapes_intersect(t_shape *shapes, t_inter *inter);

#endif