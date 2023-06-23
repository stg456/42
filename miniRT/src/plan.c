/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:48:53 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/23 15:02:53 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor)
{
	free(tmp_pos);
	free(tmp_axe);
	free(tmpcolor);
	free(tmp);
}

static void	check_plan(t_plane pl, t_data *d)
{
	if (vectinrange(pl.axe.x) || vectinrange(pl.axe.y) || vectinrange(pl.axe.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of plan not in the rang\n");
	}
	if (rgbinrange(pl.rgb.r) || rgbinrange(pl.rgb.g) || rgbinrange(pl.rgb.b)
		|| ft_isdigit(pl.rgb.r) || ft_isdigit(pl.rgb.g) || ft_isdigit(pl.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for plan\n");
	}
}

void	pl(char *buf, t_data *d)
{
	t_plane	pl;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	printf("dans pl: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	pl.pos.x = ft_atof(tmp_pos[0]);
	pl.pos.y = ft_atof(tmp_pos[1]);
	pl.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	pl.normal.x = ft_atof(tmp_axe[0]);
	pl.normal.y = ft_atof(tmp_axe[1]);
	pl.normal.z = ft_atof(tmp_axe[2]);
	pl.axe = pl.normal;
	tmpcolor = ft_split(tmp[3], ',');
	pl.rgb.r = ft_atoi(tmpcolor[0]);
	pl.rgb.g = ft_atoi(tmpcolor[1]);
	pl.rgb.b = ft_atoi(tmpcolor[2]);
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_plan(pl, d);
	d->shapes.planes[d->nbpl - 1] = pl;
	d->nbpl--;
}
