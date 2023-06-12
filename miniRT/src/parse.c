/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/12 16:09:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	amb(char *buf, t_data d)
{
	t_amb	A;
	char	**tmp;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans A: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbA += 1;
	A.ratioA = ft_atof(tmp[1]);
	tmpcolor = ft_split(tmp[2], ',');
	A.rgb.r = ft_atoi(tmpcolor[0]);
	A.rgb.g = ft_atoi(tmpcolor[1]);
	A.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp);
	return (d.nbA);
}

int	cam(char *buf, t_data d)
{
	t_cam	C;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans C: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbC += 1;
	tmp_pos = ft_split(tmp[1], ',');
	C.pos.x = ft_atof(tmp_pos[0]);
	C.pos.y = ft_atof(tmp_pos[1]);
	C.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	C.axe.x = ft_atof(tmp_axe[0]);
	C.axe.y = ft_atof(tmp_axe[1]);
	C.axe.z = ft_atof(tmp_axe[2]);
	C.fov = ft_atoi(tmp[3]);
	free(tmp);
	return (d.nbC);
}

int	lum(char *buf, t_data d)
{
	t_lum	L;
	char	**tmp;
	char	**tmp_pos;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans L: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbC += 1;
	tmp_pos = ft_split(tmp[1], ',');
	L.pos.x = ft_atof(tmp_pos[0]);
	L.pos.y = ft_atof(tmp_pos[1]);
	L.pos.z = ft_atof(tmp_pos[2]);
	L.ratioL = ft_atof(tmp[2]);
	tmpcolor = ft_split(tmp[3], ',');
	L.rgb.r = ft_atoi(tmpcolor[0]);
	L.rgb.g = ft_atoi(tmpcolor[1]);
	L.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp);
	return (d.nbL);
}

int	sp(char *buf, t_data d)
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
	free(tmp);
	return (d.nbsp);
}

int	pl(char *buf, t_data d)
{
	t_pl	pl;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans pl: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbpl += 1;
	tmp_pos = ft_split(tmp[1], ',');
	pl.pos.x = ft_atof(tmp_pos[0]);
	pl.pos.y = ft_atof(tmp_pos[1]);
	pl.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	pl.axe.x = ft_atof(tmp_axe[0]);
	pl.axe.y = ft_atof(tmp_axe[1]);
	pl.axe.z = ft_atof(tmp_axe[2]);
	tmpcolor = ft_split(tmp[3], ',');
	pl.rgb.r = ft_atoi(tmpcolor[0]);
	pl.rgb.g = ft_atoi(tmpcolor[1]);
	pl.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp);
	return (d.nbpl);
}

int	cyl(char *buf, t_data d)
{
	t_cy	cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	pass(buf);
	printf("dans cy: %s\n", buf);
	tmp = ft_split(buf, ' ');
	d.nbcy += 1;
	tmp_pos = ft_split(tmp[1], ',');
	cy.pos.x = ft_atof(tmp_pos[0]);
	cy.pos.y = ft_atof(tmp_pos[1]);
	cy.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	cy.axe.x = ft_atof(tmp_axe[0]);
	cy.axe.y = ft_atof(tmp_axe[1]);
	cy.axe.z = ft_atof(tmp_axe[2]);
	cy.diam = ft_atof(tmp[3]);
	cy.height = ft_atof(tmp[4]);
	tmpcolor = ft_split(tmp[5], ',');
	cy.rgb.r = ft_atoi(tmpcolor[0]);
	cy.rgb.g = ft_atoi(tmpcolor[1]);
	cy.rgb.b = ft_atoi(tmpcolor[2]);
	free(tmp);
	return (d.nbcy);
}
