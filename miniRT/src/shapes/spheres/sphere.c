#include "../../../inc/sphere.h"

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
	t_ray	tmp_ray;
	float	a;
	float	b;
	float	c;
	float	discri;
	float	t1;
	float	t2;

	vec_eq(&tmp_ray.axe, &inter1->ray.axe);
	tmp_ray.tMAX = inter1->ray.tMAX;
	tmp_ray.pos	= vec_opp(&sphere1->pos);
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
		return (false);
	if (inter1->pShape)
		free(inter1->pShape);
	inter1->pShape = sphere1;
	return (true);
}

bool		sphere_doesintersect(t_ray *ray1)
{

}