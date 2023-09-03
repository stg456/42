/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harowana <harowana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:48:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/02 13:13:21 by harowana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor)
{
	if (tmp_pos)
	{
		free(tmp_pos);
		tmp_pos = NULL;
	}
	if (tmp_axe)
	{
		free(tmp_axe);
		tmp_axe = NULL;
	}
	if (tmpcolor)
	{
		free(tmpcolor);
		tmpcolor = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

static void	check_plan(t_elem pl, t_data *d)
{
	if (vectinrange(pl.normal.x) || vectinrange(pl.normal.y) || vectinrange(pl.normal.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of plan not in the rang\n");
	}
}

void	pl(char *buf, t_data *d)
{
	t_elem	*pl;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	pl = elem_init();
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	pl->pos = get_coor(tmp_pos);
	tmp_axe = ft_split(tmp[2], ',');
	pl->normal = get_coor(tmp_axe);
	tmpcolor = ft_split(tmp[3], ',');
	pl->rgb = get_color(tmpcolor);
	pl->next = NULL;
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_plan(*pl, d);
	shapes_addback(&d->shapes.planes, pl, &d->shapes.plane_nb);
}
