#include "miniRT.h"

// t_plane	*plane_init(t_vec *pos, t_vec *normal)
// {
// 	t_plane	*plane;

// 	plane = malloc(sizeof(t_plane));
// 	if (!plane)
// 		return (NULL);
// 	plane->pos.x = pos->x;
// 	plane->pos.y = pos->y;
// 	plane->pos.z = pos->z;
// 	vec_eq(&plane->normal, normal);
// 	return (plane);
// }

// bool	plane_intersect(t_plane *plane, t_inter *inter)
// {
// 	float	dDotn;
// 	float 	t;
	
// 	dDotn = dot(inter->ray.axe, plane->normal);
// 	if (dDotn == 0.0f)
// 		return (false);
// 	t = dot(vecs_sus(&plane->pos, &inter->ray.pos), plane->normal) / dDotn;
// 	// t = -(dot(plane->normal, inter->ray.pos) - dot(plane->normal, plane->pos)) / dDotn;
// 	if (t <= RAY_T_MIN || t >= inter->t)
// 		return (false);
// 	inter->t = t;
// 	inter->pShape = plane;
// 	inter->pos = ray_calculate(&inter->ray, inter->t);
// 	if (dot(inter->ray.axe, plane->normal) > 0)
// 		plane->normal = vecs_multf(&plane->normal, -1);
// 	inter->normal = plane->normal;
// 	inter->rgb = plane->rgb;
// 	return (true);
// }

// bool	plane_doesintersect(t_plane *plane, t_ray *ray)
// {
// 	float	dDotn;
// 	float 	t;
	
// 	dDotn = dot(ray->axe, plane->normal);
// 	if (dDotn == 0.0f)
// 		return (false);
// 	t = dot(vecs_sus(&plane->pos, &ray->pos), plane->normal) / dDotn;
// 	if (t <= RAY_T_MIN || t >= ray->tMAX)
// 		return (false);
// 	return (true);
// }
