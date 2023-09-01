/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/01 12:47:53 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_cyl(t_cyl cy, t_data *d)
{
	if (vectinrange(cy.axe.x) || vectinrange(cy.axe.y) || vectinrange(cy.axe.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of cylinder not in the rang\n");
	}
	if (ft_isfloat(cy.pos.x) == false || ft_isfloat(cy.pos.y) == false
		|| ft_isfloat(cy.pos.z) == false)
	{
		close(d->fd);
		ft_error("Error\nproblem in data of cylinder\n");
	}
	if (cy.radius < 0)
	{
		close(d->fd);
		ft_error("Error\nproblem in length of sphere\n");
	}
}

void	cyl(char *buf, t_data *d)
{
	t_cyl	cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	cy.pos.x = ft_atof(tmp_pos[0]);
	cy.pos.y = ft_atof(tmp_pos[1]);
	cy.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	cy.axe.x = ft_atof(tmp_axe[0]);
	cy.axe.y = ft_atof(tmp_axe[1]);
	cy.axe.z = ft_atof(tmp_axe[2]);
	cy.axe = normalized(cy.axe);
	cy.radius = ft_atof(tmp[3]) / 2;
	cy.height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy.rgb = get_color(tmpcolor);
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_cyl(cy, d);
	d->shapes.cylindres[d->nbcy - 1] = cy;
	d->nbcy--;
}
