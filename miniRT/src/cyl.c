/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/10 17:11:05 by marvin           ###   ########.fr       */
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
	if (rgbinrange(cy.rgb.r) || rgbinrange(cy.rgb.g) || rgbinrange(cy.rgb.b)
		|| ft_isdigit(cy.rgb.r) || ft_isdigit(cy.rgb.g) || ft_isdigit(cy.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for cylinder\n");
	}
}

// void	cyl_calc(t_data *d)
// {
// 	int	i;

// 	i = 0;
// 	while (i < d->nbcy)
// 	{
// 		d->shapes.cylindres[i].cam_pos = vecs_sus(d->shapes.cylindres[i].pos, d->cam.pos);
// 		d->shapes.cylindres[i].matrice = matrice_cyl(&d->shapes.cylindres[i]);
// 		d->shapes.cylindres[i].cam_axe = matrice_mult(&d->shapes.cylindres[i].matrice, &d->cam.axe);
// 		i++;
// 	}
// }

void	cyl(char *buf, t_data *d)
{
	t_cyl	cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	printf("dans cy: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	cy.pos.x = ft_atof(tmp_pos[0]);
	cy.pos.y = ft_atof(tmp_pos[1]);
	cy.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	cy.axe.x = ft_atof(tmp_axe[0]);
	cy.axe.y = ft_atof(tmp_axe[1]);
	cy.axe.z = ft_atof(tmp_axe[2]);
	cy.radius = ft_atof(tmp[3]) / 2;
	cy.height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy.rgb.r = ft_atoi(tmpcolor[0]);
	cy.rgb.g = ft_atoi(tmpcolor[1]);
	cy.rgb.b = ft_atoi(tmpcolor[2]);
	cy.frgb.r = ft_atof(tmpcolor[0]) / 255;
	cy.frgb.g = ft_atof(tmpcolor[1]) / 255;
	cy.frgb.b = ft_atof(tmpcolor[2]) / 255;
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_cyl(cy, d);
	d->shapes.cylindres[d->nbcy - 1] = cy;
	d->nbcy--;
}
