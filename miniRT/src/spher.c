/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:22:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/17 19:31:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_sph(t_sphere sp, t_data *d)
{
	if (rgbinrange(sp.rgb.r) || rgbinrange(sp.rgb.g) || rgbinrange(sp.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for sphere\n");
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
	sp.rgb.r = ft_atoi(tmpcolor[0]);
	sp.rgb.g = ft_atoi(tmpcolor[1]);
	sp.rgb.b = ft_atoi(tmpcolor[2]);
	free_all(tmp_pos, tmpcolor, tmp, NULL);
	check_sph(sp, d);
	d->shapes.spheres[d->nbsp - 1] = sp;
	d->nbsp--;
}
