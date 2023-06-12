/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:59:26 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/12 18:07:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor)
{
	free(tmp_pos);
	free(tmp_axe);
	free(tmpcolor);
	free(tmp);
}

void	pl(char *buf, t_data d)
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
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
}

void	cyl(char *buf, t_data d)
{
	t_cy	cy;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;
	char	**tmpcolor;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	// pass(buf);
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
	free_all(tmp, tmp_pos, tmp_axe, tmpcolor);
}
