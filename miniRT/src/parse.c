/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/14 10:25:45 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	amb(char *buf, t_data d)
// {
// 	t_amb	a;
// 	char	**tmp;
// 	char	**tmpcolor;

// 	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
// 	pass(buf);
// 	printf("dans A: %s\n", buf);
// 	tmp = ft_split(buf, ' ');
// 	d.nbA += 1;
// 	a.ratioA = ft_atof(tmp[1]);
// 	tmpcolor = ft_split(tmp[2], ',');
// 	a.rgb.r = ft_atoi(tmpcolor[0]);
// 	a.rgb.g = ft_atoi(tmpcolor[1]);
// 	a.rgb.b = ft_atoi(tmpcolor[2]);
// 	free(tmpcolor);
// 	free(tmp);
// 	printf("amb a.rgb.b: %d\n", a.rgb.b);
// 	check_amb(a);
// }

void	cam(char *buf, t_data d)
{
	t_cam	c;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans C: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbC += 1;
	tmp_pos = ft_split(tmp[1], ',');
	c.pos.x = ft_atof(tmp_pos[0]);
	c.pos.y = ft_atof(tmp_pos[1]);
	c.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	c.axe.x = ft_atof(tmp_axe[0]);
	c.axe.y = ft_atof(tmp_axe[1]);
	c.axe.z = ft_atof(tmp_axe[2]);
	c.fov = ft_atoi(tmp[3]);
	free(tmp_pos);
	free(tmp_axe);
	free(tmp);
}

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

void	sp(char *buf, t_data d)
{
	t_sp	sp;
	char	**tmp;
	char	**tmp_pos;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans sp: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbsp += 1;
	tmp_pos = ft_split(tmp[1], ',');
	sp.pos.x = ft_atof(tmp_pos[0]);
	sp.pos.y = ft_atof(tmp_pos[1]);
	sp.pos.z = ft_atof(tmp_pos[2]);
	sp.diam = atof(tmp[2]);
	tmpcolor = ft_split(tmp[3], ',');
	sp.rgb.r = ft_atoi(tmpcolor[0]);
	sp.rgb.g = ft_atoi(tmpcolor[1]);
	sp.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp_pos);
	free(tmpcolor);
	free(tmp);
}

