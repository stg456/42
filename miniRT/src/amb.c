/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:19:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/23 12:28:33 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_amb(t_amb a, t_data *d)
{
	if (rgbinrange(a.rgb.r) || rgbinrange(a.rgb.g) || rgbinrange(a.rgb.b)
		|| ft_isdigit(a.rgb.r) || ft_isdigit(a.rgb.g) || ft_isdigit(a.rgb.b))
	{
		close(d->fd);
		ft_error("Error\nincorrect rgb value for A\n");
	}
	if (ratioinrange(a.ratioA))
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

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	printf("dans A: %s\n", buf);
	tmp = ft_split(buf, ' ');
	a.ratioA = ft_atof(tmp[1]);
	tmpcolor = ft_split(tmp[2], ',');
	a.rgb.r = ft_atoi(tmpcolor[0]);
	a.rgb.g = ft_atoi(tmpcolor[1]);
	a.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmpcolor);
	free(tmp);
	printf("a.rgb.r: %d\na.rgb.g: %d\na.rgb.b: %d\n", a.rgb.r, a.rgb.g, a.rgb.b);
	check_amb(a, d);
	d->amb = a;
}
