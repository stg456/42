/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 14:18:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	iter_lst_objs(t_inter *inter, t_elem *elem, bool *ret,
								bool (*ft)(t_inter *inter, t_elem *elem))
{
	while (elem)
	{
		*ret |= (*ft)(inter, elem);
		elem = elem->next;
	}
}

bool	shapes_intersect(t_shape *shapes, t_inter *inter)
{
	bool	hit;

	hit = false;
	if (shapes->planes != 0)
		iter_lst_objs(inter, shapes->planes, &hit, *hit_pl);
	if (shapes->cylindres != 0)
		iter_lst_objs(inter, shapes->cylindres, &hit, *hit_cy);
	if (shapes->spheres != 0)
		iter_lst_objs(inter, shapes->spheres, &hit, *hit_sp);
	return (hit);
}
