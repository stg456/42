#ifndef RAY_H
# define RAY_H

#include "vector.h"

#define RAY_T_MIN 0.0001f

#define RAY_T_MAX 1.0e30f

typedef struct s_ray
{
	t_vec	pos;
	t_vec	axe;
	float	tMAX;
}	t_ray;

//-----Instanciation----//
t_ray	*ray_init();
t_ray	*ray_cpy(t_ray *r1); // à parfaire
t_ray	*ray_init_param(t_vec pos, t_vec axe, float tMAX);
t_ray	*ray_init_param2(t_vec pos, t_vec axe);

//-----Manipulations-----//
void	ray_eq(t_ray *r1, t_ray *r2); // à parfaire


//-----Operations-----//
t_vec	ray_calculate(t_ray *r1, float t);

#endif