#ifndef SPHERE_H
# define SPHERE_H

typedef struct	s_sphere
{
	t_vec		pos; // centre
	float		radius;
	int			rgb;
}				t_sphere;

t_sphere	*sphere_init(t_vec *pos, float radius);

bool		sphere_intersect(t_sphere *sphere, t_inter *inter);
bool		sphere_doesintersect(t_sphere *sphere, t_ray *ray);

#endif