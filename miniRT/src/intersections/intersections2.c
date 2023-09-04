/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:53:52 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 16:53:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	inter_eq(t_inter *inter1, t_inter *inter2)
{
	*inter1 = inter_cpy_ray(&inter2->ray);
	inter1->t = inter2->t;
	inter1->rgb = inter2->rgb;
}

t_vec	inter_position(t_inter *inter1)
{
	return (ray_calculate(&inter1->ray, inter1->t));
}
