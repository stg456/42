#include "../../inc/ray.h"

t_ray	*ray_init()
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->pos.x = 0.0f;
	ray->pos.y = 0.0f;
	ray->pos.z = 0.0f;
	ray->axe.x = 0.0f;
	ray->axe.y = 1.0f;
	ray->axe.z = 0.0f;
	ray->tMAX = RAY_T_MAX;
	return (ray);
}

t_ray	*ray_cpy(t_ray *r1)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->pos.x = r1->pos.x;
	ray->pos.y = r1->pos.y;
	ray->pos.z = r1->pos.z;
	ray->axe.x = r1->axe.x;
	ray->axe.y = r1->axe.y;
	ray->axe.z = r1->axe.z;
	ray->tMAX = r1->tMAX;
	return (ray);
}

t_ray	*ray_init_param(t_vec pos, t_vec axe, float tMAX)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->pos = pos;
	ray->axe = axe;
	ray->tMAX = tMAX;
	return (ray);
}

t_ray	*ray_init_param2(t_vec pos, t_vec axe)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->pos = pos;
	ray->axe = axe;
	ray->tMAX = RAY_T_MAX;
	return (ray);
}