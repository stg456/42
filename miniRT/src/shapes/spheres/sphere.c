#include "miniRT.h"

t_sphere	*sphere_init(t_vec *pos, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	vec_eq(&sphere->pos, pos);
	sphere->radius = radius;
	return (sphere);
}

bool		sphere_intersect(t_sphere *sphere1, t_inter *inter1)
{
	t_vec	ray_pos;
	float	a;
	float	b;
	float	c;
	float	discri;
	float	t1;
	float	t2;

	vec_eq(&ray_pos, &inter1->ray.pos); // assigns the value of inter1->ray.pos to tmp_ray.pos
	vec_sus(&ray_pos, &sphere1->pos); // tmp_ray.pos = tmp_ray.pos - sphere1->pos
	a = dot(inter1->ray.axe, inter1->ray.axe); // Length squared of the ray direction
    b = 2 * dot(ray_pos, inter1->ray.axe);
    c = dot(ray_pos, ray_pos) - sqr(sphere1->radius);
	discri = sqr(b) - 4 * a * c;
	if (discri < 0.0f)
		return (false);
	t1 = (-b - sqrt(discri)) / (2 * a);
	t2 = (-b + sqrt(discri)) / (2 * a);
	if (t1 > RAY_T_MIN && t1 < inter1->t)
		inter1->t = t1;
	else if (t2 > RAY_T_MIN && t2 < inter1->t)
		inter1->t = t2;
	else
	{
		return (false);
	}
	inter1->pos = ray_calculate(&inter1->ray, inter1->t);
	inter1->normal = normalized(vecs_sus(&inter1->pos, &sphere1->pos));
	inter1->pShape = sphere1;
	rgb_eq(&inter1->rgb, &sphere1->rgb);
	return (true);
}

bool		sphere_doesintersect(t_sphere *sphere1, t_ray *ray1)
{
	t_ray	tmp_ray;
	float	a;
	float	b;
	float	c;
	float	discri;
	float	t1;
	float	t2;

	vec_eq(&tmp_ray.axe, &ray1->axe);
	tmp_ray.tMAX = ray1->tMAX;
	tmp_ray.pos	= vec_opp(&sphere1->pos);
	a = dot(tmp_ray.axe, tmp_ray.axe);
	b = 2 * dot(tmp_ray.axe, tmp_ray.pos);
	c = dot(tmp_ray.pos, tmp_ray.pos) -  sqr(sphere1->radius);
	discri = sqr(b) - 4 * a * c;
	if (discri < 0.0f)
		return (false);
	t1 = (-b - sqrt(discri)) / (2 * a);
	if (t1 > RAY_T_MIN && t1 < ray1->tMAX)
		return (true);
	t2 = (-b + sqrt(discri)) / (2 * a);
	if (t2 > RAY_T_MIN && t2 < ray1->tMAX)
		return (true);
	return (false);
}
