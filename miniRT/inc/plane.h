#ifndef PLANE_H
# define PLANE_H

typedef struct	s_plane
{
	t_vec		pos;
	t_vec		normal;
	int			rgb;
}				t_plane;

t_plane	*plane_init(t_vec *pos, t_vec *normal);

bool	plane_intersect(t_plane *plane, t_inter *inter);
bool	plane_doesintersect(t_plane *plane, t_ray *ray);

#endif