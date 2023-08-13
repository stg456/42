#include "miniRT.h"

t_inter	inter_init()
{
	t_inter	inter;

	inter.ray.pos.x = 0.0f;
	inter.ray.pos.y = 0.0f;
	inter.ray.pos.z = 0.0f;
	inter.ray.axe.x = 0.0f;
	inter.ray.axe.y = 1.0f;
	inter.ray.axe.z = 0.0f;
	inter.ray.tMAX = RAY_T_MAX;
	inter.t = RAY_T_MAX;
	inter.pShape = NULL;
	return (inter);
}

t_inter	inter_cpy(t_inter *inter1)
{
	t_inter	inter;

	ray_eq(&inter.ray, &inter1->ray);
	inter.t = inter1->t;
	inter.pShape = inter1->pShape; // ! keep an eye on !
	inter.frgb = inter1->frgb;
	return (inter);
}

t_inter	inter_cpy_ray(t_ray *ray1)
{
	t_inter	inter;

	ray_eq(&inter.ray, ray1);
	inter.t = ray1->tMAX;
	inter.pShape = NULL;
	return (inter);
}

float	sqr(float f)
{
	return (f * f);
}