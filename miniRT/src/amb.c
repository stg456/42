/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:19:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/03 18:25:17 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_amb(t_amb a, t_data *d/*, char **tmp*/)
{
	if (ratioinrange(a.ratio))
	{
		close(d->fd);
		ft_error("Error\nincorrect ratio value for A\n");
	}
	// if (ft_isfloat(tmp[1]))
	// {
	// 	close(d->fd);
	// 	ft_error("Error\nincorrect value for A\n");
	// }
}

void	amb(char *buf, t_data *d)
{
	t_amb	a;
	char	**tmp;
	char	**tmpcolor;

	tmp = ft_split(buf, ' ');
	a.ratio = ft_atof(tmp[1]);
	tmpcolor = ft_split(tmp[2], ',');
	a.rgb = get_color(tmpcolor);
	free_all(tmp, tmpcolor, NULL, NULL);
	check_amb(a, d/*, tmp*/);
	d->amb = a;
}
