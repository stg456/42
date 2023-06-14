#include "../../inc/intersection.h"

t_inter	*inter_init()
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (NULL);
	inter->ray.pos.x = 0.0f;
	inter->ray.pos.y = 0.0f;
	inter->ray.pos.z = 0.0f;
	inter->ray.axe.x = 0.0f;
	inter->ray.axe.y = 1.0f;
	inter->ray.axe.z = 0.0f;
	inter->ray.tMAX = RAY_T_MAX;
	inter->t = RAY_T_MAX;
	inter->pShape = NULL;
}

t_inter	*inter_cpy(t_inter *inter1)
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (NULL);
	ray_eq(&inter->ray, &inter1->ray);
	inter->t = inter1->t;
	shape_eq(inter->pShape, inter1->pShape); // potentially change to pointer assignation
	return (inter);
}

t_inter	*inter_cpy_ray(t_ray *ray1)
{
	t_inter	*inter;

	inter = malloc(sizeof(t_inter));
	if (!inter)
		return (NULL);
	ray_eq(&inter->ray, ray1);
	inter->t = ray1->tMAX;
	inter->pShape = NULL;
	return (inter);
}