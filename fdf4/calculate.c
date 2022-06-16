/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:46:12 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 15:56:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_m3	*calculate_point(t_m3 *p, t_cam *c, t_env *e)
{
	t_m3	*tmp;
	t_m3	*coord;
	double	x;
	double	y;
	double	z;

	x = (p->x * e->space) - c->x;
	y = (p->y * e->space) - c->y;
	z = p->z - c->z;
	tmp = new_m3(0, 0, 0, 0);
	coord = new_m3(0, 0, 0, p->end);
	tmp->x = (cos(c->ry) * ((sin(c->rz) * y) + (cos(c->rz) * x))) - (sin(c->ry)
			* z);
	tmp->y = (sin(c->rx) * ((cos(c->ry) * z) + (sin(c->ry) * ((sin(c->ry) * y)
			+ (cos(c->rz) * x))))) + (cos(c->rx) * ((cos(c->ry) * y)
			- (sin(c->rz) * x)));
	tmp->z = (cos(c->rx) * ((cos(c->ry) * z) + (sin(c->ry) * ((sin(c->ry) * y)
			+ (cos(c->rz) * x))))) - (sin(c->rx) * ((cos(c->rz) * y)
			- (sin(c->rz) * x)));
	coord->x = (c->fov / tmp->z) * tmp->x;
	coord->y = (c->fov / tmp->z) * tmp->y;
	free(tmp);
	return (coord);
}