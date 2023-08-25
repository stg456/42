/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:22:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/21 11:49:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	sp.radius = atof(tmp[2]) / 2; // can only be positive -> add check
	tmpcolor = ft_split(tmp[3], ',');
	sp.rgb = get_color(tmpcolor);
	free_all(tmp_pos, tmpcolor, tmp, NULL);
	d->shapes.spheres[d->nbsp - 1] = sp;
	d->nbsp--;
}
