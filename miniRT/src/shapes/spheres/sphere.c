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

bool		sphere_intersect(t_sphere *sphere1, t_inter *inter1) // à raccourcir
{
	t_ray	tmp_ray;
	float	a;
	float	b;
	float	c;
	float	discri;
	float	t1;
	float	t2;

	vec_eq(&tmp_ray.axe, &inter1->ray.axe);
	vec_eq(&tmp_ray.pos, &inter1->ray.pos);
	tmp_ray.tMAX = inter1->ray.tMAX;
	vec_sus(&tmp_ray.pos, &sphere1->pos);
	a = length2(&tmp_ray.axe);
	b = 2 * dot(tmp_ray.axe, tmp_ray.pos);
	c = length2(&tmp_ray.pos) -  sqrt(sphere1->radius);
	discri = sqrt(b) - 4 * a * c;
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
		printf("Nope\nt1 = %f\nt2 = %f\n", t1, t2);
		return (false);
	}
	inter1->pShape = sphere1;
	inter1->frgb = sphere1->frgb;
	printf("Sphere intersection:\ninter1->t: %f\ninter1->frgb: r:%f g:%f b:%f\n", inter1->t, inter1->frgb.r, inter1->frgb.g, inter1->frgb.b);
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
	a = length2(&tmp_ray.axe);
	b = 2 * dot(tmp_ray.axe, tmp_ray.pos);
	c = length2(&tmp_ray.pos) -  sqrt(sphere1->radius);
	discri = sqrt(b) - 4 * a * c;
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
