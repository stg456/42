/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:48:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/21 11:50:43 by marvin           ###   ########.fr       */
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

static void	check_plan(t_plane pl, t_data *d)
{
	if (vectinrange(pl.normal.x) || vectinrange(pl.normal.y) || vectinrange(pl.normal.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of plan not in the rang\n");
	}
}

void	pl(char *buf, t_data *d)
{
	t_plane	pl;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	pl.pos.x = ft_atof(tmp_pos[0]);
	pl.pos.y = ft_atof(tmp_pos[1]);
	pl.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	pl.normal.x = ft_atof(tmp_axe[0]);
	pl.normal.y = ft_atof(tmp_axe[1]);
	pl.normal.z = ft_atof(tmp_axe[2]);
	tmpcolor = ft_split(tmp[3], ',');
	pl.rgb = get_color(tmpcolor);
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_plan(pl, d);
	d->shapes.planes[d->nbpl - 1] = pl;
	d->nbpl--;
}
