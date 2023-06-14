#include "../../inc/intersection.h"

void	inter_eq(t_inter *inter1, t_inter *inter2)
{
	inter1->ray = inter2->ray;
	inter1->t = inter2->t;
	if (inter1->pShape)
		free(inter1->pShape);
	shape_eq(inter1->pShape, inter2->pShape);
}

bool	intersected(t_inter *inter1)
{
	return (inter1->pShape != NULL);
}

t_vec	inter_position(t_inter *inter1)
{
	return (ray_calculate(&inter1->ray, inter1->t));
}