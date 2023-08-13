#include "miniRT.h"

t_plane	*plane_init(t_vec *pos, t_vec *normal)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->pos.x = pos->x;
	plane->pos.y = pos->y;
	plane->pos.z = pos->z;
	vec_eq(&plane->normal, normal);
	return (plane);
}

bool	plane_intersect(t_plane *plane1, t_inter *inter1)
{
	float	dDotn;
	float 	t;
	
	dDotn = dot(inter1->ray.axe, plane1->normal);
	if (dDotn == 0.0f)
		return (false);
	t = dot(vecs_sus(&plane1->pos, &inter1->ray.pos), plane1->normal) / dDotn;
	if (t <= RAY_T_MIN || t >= inter1->t)
		return (false);
	inter1->t = t;
	inter1->pShape = plane1;
	rgb_eq(&inter1->rgb, &plane1->rgb);
	return (true);
}

bool	plane_doesintersect(t_plane *plane1, t_ray *ray1)
{
	float	dDotn;
	float 	t;
	
	dDotn = dot(ray1->axe, plane1->normal);
	if (dDotn == 0.0f)
		return (false);
	t = dot(vecs_sus(&plane1->pos, &ray1->pos), plane1->normal) / dDotn;
	if (t <= RAY_T_MIN || t >= ray1->tMAX)
		return (false);
	return (true);
}
