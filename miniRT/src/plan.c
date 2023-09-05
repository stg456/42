/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:48:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 10:00:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl(char *buf, t_data *d)
{
	t_elem	*pl;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	pl = elem_init();
	tmp = ft_split(buf, ' ');
	if (split_count(tmp) != 4)
		ft_error("Invalid plane data\n");
	tmp_pos = ft_split(tmp[1], ',');
	check_pos(d, tmp_pos);
	pl->pos = get_coor(tmp_pos);
	tmp_axe = ft_split(tmp[2], ',');
	vectinrange(d, tmp_axe);
	pl->normal = get_coor(tmp_axe);
	tmpcolor = ft_split(tmp[3], ',');
	pl->rgb = get_color(tmpcolor);
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	shapes_addback(&d->shapes.planes, pl, &d->shapes.plane_nb);
}
