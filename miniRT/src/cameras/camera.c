/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <jlorber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:40:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/23 15:52:45 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	check_cam(t_cam c, t_data *d)
{
	if (fovinrange(c.fov_i))
	{
		close(d->fd);
		ft_error("Error\nFOV of camera not in the range\n");
	}
	if (vectinrange(c.forward.x) || vectinrange(c.forward.y) || vectinrange(c.forward.z))
	{
		close(d->fd);
		ft_error("Error\norientation vector of camera not in the range\n");
	}
}

void	cam(char *buf, t_data *d)
{
	t_cam	c;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;

	tmp = malloc(sizeof(char *) * ft_strlen(buf) + 1);
	printf("dans C: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	c.pos.x = ft_atof(tmp_pos[0]);
	c.pos.y = ft_atof(tmp_pos[1]);
	c.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	// On assigne directement à c.forward parce que le vector donné est déjà normalisé
	c.forward.x = ft_atof(tmp_axe[0]);
	c.forward.y = ft_atof(tmp_axe[1]);
	c.forward.z = ft_atof(tmp_axe[2]);
	c.fov_i = ft_atoi(tmp[3]);
	c.fov = ft_atoi(tmp[3]) * PI / 180;
	free_all(tmp, tmp_pos, tmp_axe, NULL);
	//on envoie une référence de c à cam_init pour finir de compléter notre structure
	cam_init(&c, d->env.size_x / d->env.size_y);
	// printf("cam c.fov: %d\n", c.fov);
	check_cam(c, d);
	d->cam = c;
}
