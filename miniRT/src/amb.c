/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:19:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 14:57:45 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	sqr(float f)
{
	return (f * f);
}

void	amb(char *buf, t_data *d)
{
	t_amb	a;
	char	**tmp;
	char	**tmpcolor;

	tmp = ft_split(buf, ' ');
	if (split_count(tmp) != 3)
		ft_error("Invalid ambiant light data\n");
	if (!ft_isfloat(tmp[1]) || ratioinrange(tmp[1]))
		ft_error("Error\nInvalid ratio value for ambiant light\n");
	a.ratio = ft_atof(tmp[1]);
	tmpcolor = ft_split(tmp[2], ',');
	a.rgb = get_color(tmpcolor);
	free_all(tmp, tmpcolor, NULL, NULL);
	d->amb = a;
}
