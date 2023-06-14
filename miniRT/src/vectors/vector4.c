#include "../../inc/vector.h"

t_vec2   *vec2_init()
{
    t_vec2   *vec;

    vec = malloc(sizeof(t_vec2));
    if (!vec)
        return (NULL);
    vec->u = 0.0f;
    vec->v = 0.0f;
}

t_vec2   *vec2_cpy(t_vec2 *v1)
{
    t_vec2   *vec;

    vec = malloc(sizeof(v1));
    if (!vec)
        return (NULL);
    vec->u = v1->u;
    vec->v = v1->v;
    return(vec);
}

t_vec2   *vec2_init_fs(float u, float v)
{
    t_vec2   *vec;

    v = malloc(sizeof(t_vec2));
    if (!v)
        return (NULL);
    vec->u = u;
    vec->v = v;
    return (vec);
}

t_vec2   *vec2_init_f(float f)
{
    t_vec2   *vec;

    vec = malloc(sizeof(t_vec2));
    if (!vec)
        return (NULL);
    vec->u = f;
    vec->v = f;
    return (vec);
}

void	vec2_eq(t_vec2 *v1, t_vec2 *v2)
{
	v1->u = v2->u;
	v1->v = v2->v;
}
