/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:42:31 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/20 18:45:25 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_lum(t_lum l, t_data *d)
{
	if (rgbinrange(l.rgb.r) || rgbinrange(l.rgb.g) || rgbinrange(l.rgb.b)
		|| ft_isdigit(l.rgb.r) || ft_isdigit(l.rgb.g) || ft_isdigit(l.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for L\n");
	}
	if (ratioinrange(l.ratioL))
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

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	printf("dans L: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	l.pos.x = ft_atof(tmp_pos[0]);
	l.pos.y = ft_atof(tmp_pos[1]);
	l.pos.z = ft_atof(tmp_pos[2]);
	l.ratioL = ft_atof(tmp[2]);
	tmpcolor = ft_split(tmp[3], ',');
	l.rgb.r = ft_atoi(tmpcolor[0]);
	l.rgb.g = ft_atoi(tmpcolor[1]);
	l.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp_pos);
	free(tmpcolor);
	free(tmp);
	check_lum(l, d);
	d->lum = l;
}
