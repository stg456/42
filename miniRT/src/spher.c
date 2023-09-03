/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:22:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/03 18:28:23 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_pos(t_elem *sp, t_data *d, char **tmp_pos) // il faut un char *pos
{
	(void) sp;
	(void) d;
	(void) tmp_pos;
	// if (ft_isfloat(tmp_pos[0]) || ft_isfloat(tmp_pos[1])
	// 	|| ft_isfloat(tmp_pos[2]))
	// {
	// 	close(d->fd);
	// 	ft_error("Error\nproblem in data of sphere\n");
	// }
	return (0);
}

// static void	check_sphere(t_elem *sp, t_data *d)
// {
// 	(void) sp;
// 	(void) *d;
// 	// if (ft_isfloat(sp.pos.x) || ft_isfloat(sp.pos.y)
// 	// 	|| ft_isfloat(sp.pos.z))
// 	// {
// 	// 	close(d->fd);
// 	// 	ft_error("Error\nproblem in data of sphere\n");
// 	// }
// 	if (sp->radius < 0)
// 	{
// 		close(d->fd);
// 		ft_error("Error\nproblem in length of sphere\n");
// 	}
// }

void	sp(char *buf, t_data *d)
{
	t_elem		*sp;
	char		**tmp;
	char		**tmp_pos;
	char		**tmpcolor;

	sp = elem_init();
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	check_pos(sp, d, tmp_pos);
	sp->pos = get_coor(tmp_pos);
	sp->radius = atof(tmp[2]) / 2; // can only be positive -> add check
	tmpcolor = ft_split(tmp[3], ',');
	sp->rgb = get_color(tmpcolor);
	sp->next = NULL;
	free_all(tmp_pos, tmpcolor, tmp, NULL);
	shapes_addback(&d->shapes.spheres, sp, &d->shapes.sphere_nb);
}
