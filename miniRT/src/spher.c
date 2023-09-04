/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:22:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 12:44:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_pos(t_data *d, char **pos)
{
	if (ft_isfloat(pos[0]) == false || ft_isfloat(pos[1]) == false
		|| ft_isfloat(pos[2]) == false)
	{
		close(d->fd);
		ft_error("Error\nShape position is invalid\n");
	}
}

void	check_radius(t_data *d, char *radius)
{
	if (ft_isfloat(radius) == false || ft_atof(radius) < 0)
	{
		close(d->fd);
		ft_error("Error\nShape radius is invalid\n");
	}
}

void	sp(char *buf, t_data *d)
{
	t_elem		*sp;
	char		**tmp;
	char		**tmp_pos;
	char		**tmpcolor;

	sp = elem_init();
	tmp = ft_split(buf, ' ');
	if (split_count(tmp) != 4)
		ft_error("Error\nInvalid sphere data\n");
	tmp_pos = ft_split(tmp[1], ',');
	check_pos(d, tmp_pos);
	sp->pos = get_coor(tmp_pos);
	check_radius(d, tmp[2]);
	sp->radius = atof(tmp[2]) / 2;
	tmpcolor = ft_split(tmp[3], ',');
	sp->rgb = get_color(tmpcolor);
	sp->next = NULL;
	free_all(tmp_pos, tmpcolor, tmp, NULL);
	shapes_addback(&d->shapes.spheres, sp, &d->shapes.sphere_nb);
}
