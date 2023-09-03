/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/01 12:47:53 by stgerard         ###   ########.fr       */
=======
/*   By: harowana <harowana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:50:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/02 13:13:21 by harowana         ###   ########.fr       */
>>>>>>> 0e34075369356347c7dcbf2c766131f4b1bdcb69
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_cyl(t_elem cy, t_data *d)
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
	t_elem	*cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	cy = elem_init();
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	cy->pos = get_coor(tmp_pos);
	tmp_axe = ft_split(tmp[2], ',');
	cy->axe = normalized(get_coor(tmp_axe));
	cy->radius = ft_atof(tmp[3]) / 2;
	cy->height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy->rgb = get_color(tmpcolor);
	cy->next = NULL;
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
	check_cyl(*cy, d);
	shapes_addback(&d->shapes.cylindres, cy, &d->shapes.cyl_nb);
}
