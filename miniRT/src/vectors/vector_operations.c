/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:21:15 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 14:22:30 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vecs_add(t_vec v1, t_vec v2)
{
	t_vec	vec;

	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	return (vec);
}

t_vec	vecs_sus(t_vec v1, t_vec v2)
{
	t_vec	vec;

	vec.x = v1.x - v2.x;
	vec.y = v1.y - v2.y;
	vec.z = v1.z - v2.z;
	return (vec);
}

t_vec	vecs_multf(t_vec v1, float f)
{
	t_vec	vec;

	vec.x = v1.x * f;
	vec.y = v1.y * f;
	vec.z = v1.z * f;
	return (vec);
}
