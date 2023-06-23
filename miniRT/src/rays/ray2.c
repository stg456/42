#include "miniRT.h"

void	ray_eq(t_ray *r1, t_ray *r2)
{
	r1->pos.x = r2->pos.x;
	r1->pos.y = r2->pos.y;
	r1->pos.z = r2->pos.z;
	r1->axe.x = r2->axe.x;
	r1->axe.y = r2->axe.y;
	r1->axe.z = r2->axe.z;
	r1->tMAX = r2->tMAX;
}

t_vec	ray_calculate(t_ray *r1, float t)
{
	t_vec	tmp;
	tmp = vecs_add(&r1->pos, &r1->axe);
	return (vecs_multf(&tmp, t));
}