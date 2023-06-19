/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:19:41 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/19 17:23:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_amb(t_amb a, t_data d)
{
	if (rgbinrange(a.rgb.r) || rgbinrange(a.rgb.g) || rgbinrange(a.rgb.b)
		|| ft_isdigit(a.rgb.r) || ft_isdigit(a.rgb.g) || ft_isdigit(a.rgb.b))
		ft_error("Error\nincorrect rgb value for A\n"/*, d*/);
	{
		close(d.fd);
		ft_error("Error\nincorrect rgb value for A\n");
	}
	// if (ratioinrange(a.ratioA))
	{
		close(d.fd);
		ft_error("Error\nincorrect ratio value for A\n");
	}
	// printf("check2b a.rgb.b: %d\n", a.rgb.b);
	// printf("rgbinrange(a.rgb.b): %d\n", rgbinrange(a.rgb.b));
	// printf("a.ratio: %lf\n", a.ratioA);
	// printf("ratioinrange(a.rgb.b): %d\n", ratioinrange(a.rgb.b));
}

void	amb(char *buf, t_data d)
{
	t_amb	a;
	char	**tmp;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	printf("dans A: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbA += 1;
	a.ratioA = ft_atof(tmp[1]);
	tmpcolor = ft_split(tmp[2], ',');
	a.rgb.r = ft_atoi(tmpcolor[0]);
	a.rgb.g = ft_atoi(tmpcolor[1]);
	a.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmpcolor);
	free(tmp);
	check_amb(a, d);
}
