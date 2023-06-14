/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:42:31 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/14 10:47:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	lum(char *buf, t_data d)
{
	t_lum	l;
	char	**tmp;
	char	**tmp_pos;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans L: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbC += 1;
	tmp_pos = ft_split(tmp[1], ',');
	l.pos.x = ft_atof(tmp_pos[0]);
	l.pos.y = ft_atof(tmp_pos[1]);
	l.pos.z = ft_atof(tmp_pos[2]);
	l.ratioL = ft_atof(tmp[2]);
	tmpcolor = ft_split(tmp[3], ',');
	l.rgb.r = ft_atoi(tmpcolor[0]);
	l.rgb.g = ft_atoi(tmpcolor[1]);
	l.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp_pos);
	free(tmpcolor);
	free(tmp);
}