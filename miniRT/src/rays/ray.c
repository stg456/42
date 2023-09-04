/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:40 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 14:18:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_eq(t_ray *r1, t_ray *r2)
{
	r1->pos.x = r2->pos.x;
	r1->pos.y = r2->pos.y;
	r1->pos.z = r2->pos.z;
	r1->axe.x = r2->axe.x;
	r1->axe.y = r2->axe.y;
	r1->axe.z = r2->axe.z;
	r1->tMAX = r2->tMAX;
}

t_vec	ray_calculate(t_ray *r1, float t)
{
	t_vec	tmp;

	tmp = vecs_multf(r1->axe, t);
	return (vecs_add(r1->pos, tmp));
}
