#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "miniRT.h"

typedef struct s_vec
{
    float x;
    float y;
    float z;
}   t_vec;

typedef struct s_vec2
{
    float u;
    float v;
}   t_vec2;

//-----Instanciation-----//
t_vec   *vec_init();
t_vec   *vec_cpy(t_vec *v1);
t_vec   *vec_init_fs(float x, float y, float z);
t_vec   *vec_init_f(float f);

//-----Manipulations-----//
float   length(t_vec *vec);
float   length2(t_vec *vec);
float   normalize(t_vec *vec);
t_vec   *normalized(t_vec *vec); // potentiellement modifier type de retour

float   dot(t_vec v1, t_vec v2);
t_vec   *cross(t_vec v1, t_vec v2);

//-----Operations-----//
// Result of the operation -> v1
void    vec_add(t_vec *v1, t_vec *v2);
void    vec_sus(t_vec *v1, t_vec *v2);
void    vec_mult(t_vec *v1, float f);
void    vec_div(t_vec *v1, float f);
void	vec_eq(t_vec *v1, t_vec *v2);

// Result of the operation -> new vector
t_vec   vec_opp(t_vec *vec);
t_vec   vecs_add(t_vec *v1, t_vec *v2);
t_vec   vecs_sus(t_vec *v1, t_vec *v2);
t_vec   vecs_susf(t_vec *v1, float f);
t_vec   vecs_susf2(float f, t_vec *v1);

t_vec   vecs_mult(t_vec *v1, t_vec *v2);
t_vec   vecs_multf(t_vec *v1, float f);

t_vec   vecs_div(t_vec *v1, t_vec *v2);
t_vec   vecs_divf(t_vec *v1, float f);
t_vec   vecs_divf2(float f, t_vec *v1);

//-----t_vec2-----//
t_vec2   vec2_init();
t_vec2   vec2_cpy(t_vec2 *v1);
t_vec2   vec2_init_fs(float u, float v);
t_vec2   vec2_init_f(float f);
void     vec2_eq(t_vec2 *v1, t_vec2 *v2);

#endif