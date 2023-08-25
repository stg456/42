/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:19:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/21 11:48:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_amb(t_amb a, t_data *d)
{
	if (ratioinrange(a.ratio))
	{
		close(d->fd);
		ft_error("Error\nincorrect ratio value for A\n");
	}
	// printf("check2b a.rgb.b: %d\n", a.rgb.b);
	// printf("rgbinrange(a.rgb.b): %d\n", rgbinrange(a.rgb.b));
	// printf("a.ratio: %lf\n", a.ratioA);
	// printf("ratioinrange(a.rgb.b): %d\n", ratioinrange(a.rgb.b));
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
	check_amb(a, d);
	d->amb = a;
}
