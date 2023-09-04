/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 12:23:55 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cyl(char *buf, t_data *d)
{
	t_elem	*cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	cy = elem_init();
	tmp = ft_split(buf, ' ');
	if (split_count(tmp) != 6)
		ft_error("Invalid cylinder data\n");
	tmp_pos = ft_split(tmp[1], ',');
	check_pos(d, tmp_pos);
	cy->pos = get_coor(tmp_pos);
	tmp_axe = ft_split(tmp[2], ',');
	vectinrange(d, tmp_axe);
	cy->axe = normalized(get_coor(tmp_axe));
	check_radius(d, tmp[3]);
	cy->radius = ft_atof(tmp[3]) / 2;
	check_radius(d, tmp[4]);
	cy->height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy->rgb = get_color(tmpcolor);
	cy->next = NULL;
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	shapes_addback(&d->shapes.cylindres, cy, &d->shapes.cyl_nb);
}
