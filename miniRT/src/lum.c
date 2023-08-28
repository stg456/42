/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:42:31 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/27 15:39:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_lum(t_lum l, t_data *d)
{
	if (ratioinrange(l.ratio))
	{
		close(d->fd);
		ft_error("Error\nincorrect ratio value for L\n");
	}
}

void	lum(char *buf, t_data *d)
{
	t_lum	l;
	char	**tmp;
	char	**tmp_pos;
	char	**tmpcolor;

	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	l.pos.x = ft_atof(tmp_pos[0]);
	l.pos.y = ft_atof(tmp_pos[1]);
	l.pos.z = ft_atof(tmp_pos[2]);
	l.ratio = ft_atof(tmp[2]);
	tmpcolor = ft_split(tmp[3], ',');
	l.rgb = get_color(tmpcolor);
	free_all(tmp, tmp_pos, tmpcolor, NULL);
	check_lum(l, d);
	d->lum = l;
}
