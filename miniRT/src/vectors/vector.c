/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:18:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 11:28:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_init(void)
{
	t_vec	vec;

	vec.x = 0.0f;
	vec.y = 1.0f;
	vec.z = 0.0f;
	return (vec);
}

t_vec	vec_cpy(t_vec *v1)
{
	t_vec	vec;

	vec.x = v1->x;
	vec.y = v1->y;
	vec.z = v1->z;
	return (vec);
}

t_vec	vec_init_fs(float x, float y, float z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vec_init_f(float f)
{
	t_vec	vec;

	vec.x = f;
	vec.y = f;
	vec.z = f;
	return (vec);
}

t_vec2	vec2_init(float u, float v)
{
	t_vec2	vec;

	vec.u = u;
	vec.v = v;
	return (vec);
}
