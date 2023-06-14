/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:40:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/14 10:47:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

