#include "miniRT.h"

void    vec_add(t_vec *v1, t_vec *v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
    v1->z += v2->z;
}

void    vec_sus(t_vec *v1, t_vec *v2)
{
    v1->x -= v2->x;
    v1->y -= v2->y;
    v1->z -= v2->z;
}

void    vec_mult(t_vec *v1, float f)
{
    v1->x *= f;
    v1->y *= f;
    v1->z *= f;
}

void    vec_div(t_vec *v1, float f)
{
    v1->x /= f;
    v1->y /= f;
    v1->z /= f;
}

void	vec_eq(t_vec *v1, t_vec *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
}
