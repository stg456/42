#include "../../inc/vector.h"

t_vec   vec_opp(t_vec *vec)
{
    t_vec   v;

    v.x = -vec->x;
    v.y = -vec->y;
    v.z = -vec->z;
    return (v);
}

t_vec   vecs_add(t_vec *v1, t_vec *v2)
{
	t_vec	vec;

	vec.x = v1->x + v2->x;
	vec.y = v1->y + v2->y;
	vec.z = v1->z + v2->z;
	return (vec);
}

t_vec   vecs_sus(t_vec *v1, t_vec *v2)
{
	t_vec	vec;

	vec.x = v1->x - v2->x;
	vec.y = v1->y - v2->y;
	vec.z = v1->z - v2->z;
	return (vec);
}

t_vec   vecs_susf(t_vec *v1, float f)
{
	t_vec	vec;

	vec.x = v1->x - f;
	vec.y = v1->y - f;
	vec.z = v1->z - f;
	return (vec);
}

t_vec   vecs_susf2(float f, t_vec *v1)
{
	t_vec	vec;
	
	vec.x = f - v1->x;
	vec.y = f - v1->y;
	vec.z = f - v1->z;
	return (vec);
}
