#include "../../inc/vector.h"

t_vec   *vec_init()
{
    t_vec   *vec;

    vec = malloc(sizeof(t_vec));
    if (!vec)
        return (NULL);
    vec->x = 0.0f;
    vec->y = 1.0f;
    vec->z = 0.0f;
}

t_vec   *vec_cpy(t_vec *v1)
{
    t_vec   *vec;

    vec = malloc(sizeof(v1));
    if (!vec)
        return (NULL);
    vec->x = v1->x;
    vec->y = v1->y;
    vec->z = v1->z;
    return(vec);
}

t_vec   *vec_init_fs(float x, float y, float z)
{
    t_vec   *vec;

    vec = malloc(sizeof(t_vec));
    if (!vec)
        return (NULL);
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return (vec);
}

t_vec   *vec_init_f(float f)
{
    t_vec   *vec;

    vec = malloc(sizeof(t_vec));
    if (!vec)
        return (NULL);
    vec->x = f;
    vec->y = f;
    vec->z = f;
    return (vec);
}
