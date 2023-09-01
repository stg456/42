/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:22:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/01 12:27:17 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_sphere(t_cyl cy, t_data *d)
{
	if (ft_isfloat(sp.pos.x) == false || ft_isfloat(sp.pos.y) == false
		|| ft_isfloat(sp.pos.z) == false)
	{
		close(d->fd);
		ft_error("Error\nproblem in data of sphere\n");
	}
	if (sp.radius < 0)
	{
		close(d->fd);
		ft_error("Error\nproblem in length of sphere\n");
	}
}

void	sp(char *buf, t_data *d)
{
	t_sphere	sp;
	char		**tmp;
	char		**tmp_pos;
	char		**tmpcolor;

	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	sp.pos.x = ft_atof(tmp_pos[0]);
	sp.pos.y = ft_atof(tmp_pos[1]);
	sp.pos.z = ft_atof(tmp_pos[2]);
	sp.radius = atof(tmp[2]) / 2;
	tmpcolor = ft_split(tmp[3], ',');
	sp.rgb = get_color(tmpcolor);
	free_all(tmp_pos, tmpcolor, tmp, NULL);
	check_sphere(sp, d);
	d->shapes.spheres[d->nbsp - 1] = sp;
	d->nbsp--;
}
