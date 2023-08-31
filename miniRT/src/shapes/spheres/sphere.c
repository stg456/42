#include "miniRT.h"

// t_sphere	*sphere_init(t_vec *pos, float radius)
// {
// 	t_sphere	*sphere;

// 	sphere = malloc(sizeof(t_sphere));
// 	if (!sphere)
// 		return (NULL);
// 	vec_eq(&sphere->pos, pos);
// 	sphere->radius = radius;
// 	return (sphere);
// }

// bool		sphere_intersect(t_sphere *sphere, t_inter *inter)
// {
// 	t_vec	ray_pos;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	discri;
// 	float	t1;
// 	float	t2;

// 	vec_eq(&ray_pos, &inter->ray.pos);
// 	vec_sus(&ray_pos, &sphere->pos);
// 	a = dot(inter->ray.axe, inter->ray.axe);
//     b = 2 * dot(ray_pos, inter->ray.axe);
//     c = dot(ray_pos, ray_pos) - sqr(sphere->radius);
// 	discri = sqr(b) - 4 * a * c;
// 	if (discri < 0.0f)
// 		return (false);
// 	t1 = (-b - sqrt(discri)) / (2 * a);
// 	t2 = (-b + sqrt(discri)) / (2 * a);
// 	if (t1 > RAY_T_MIN && t1 < inter->t)
// 		inter->t = t1;
// 	else if (t2 > RAY_T_MIN && t2 < inter->t)
// 		inter->t = t2;
// 	else
// 		return (false);
// 	inter->pos = ray_calculate(&inter->ray, inter->t);
// 	inter->normal = normalized(vecs_sus(&inter->pos, &sphere->pos));
// 	inter->pShape = sphere;
// 	inter->rgb = sphere->rgb;
// 	return (true);
// }

// bool		sphere_doesintersect(t_sphere *sphere, t_ray *ray)
// {
// 	t_vec	ray_pos;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	discri;
// 	float	t1;
// 	float	t2;

// 	vec_eq(&ray_pos, &ray->pos);
// 	vec_sus(&ray_pos, &sphere->pos);
// 	a = dot(ray->axe, ray->axe);
//     b = 2 * dot(ray_pos, ray->axe);
//     c = dot(ray_pos, ray_pos) - sqr(sphere->radius);
// 	discri = sqr(b) - 4 * a * c;
// 	if (discri < 0.0f)
// 		return (false);
// 	t1 = (-b - sqrt(discri)) / (2 * a);
// 	if (t1 > RAY_T_MIN && t1 < ray->tMAX)
// 		return (true);
// 	t2 = (-b + sqrt(discri)) / (2 * a);
// 	if (t2 > RAY_T_MIN && t2 < ray->tMAX)
// 		return (true);
// 	return (false);
// }
