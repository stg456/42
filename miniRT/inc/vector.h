/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:51:52 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 15:39:37 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct s_vec2
{
	float	u;
	float	v;
}				t_vec2;

//-----Instanciation-----//
t_vec	vec_init(void);
t_vec	vec_cpy(t_vec *v1);
t_vec	vec_init_fs(float x, float y, float z);
t_vec	vec_init_f(float f);

//-----Manipulations-----//
float	length(t_vec *vec);
float	length2(t_vec *vec);
float	normalize(t_vec *vec);
t_vec	normalized(t_vec vec);

float	dot(t_vec v1, t_vec v2);
t_vec	cross(t_vec v1, t_vec v2);

//-----Operations-----//
// Result of the operation -> new vector
t_vec	vecs_add(t_vec v1, t_vec v2);
t_vec	vecs_sus(t_vec v1, t_vec v2);
t_vec	vecs_multf(t_vec v1, float f);

//-----t_vec2-----//
t_vec2	vec2_init(float u, float v);

#endif
