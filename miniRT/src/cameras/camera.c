/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:40:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/07/24 11:10:56 by nathan           ###   ########.fr       */
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
	t_cam	cam;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;

	printf("dans C: %s\n", buf);
	tmp = ft_split(buf, ' ');
	tmp_pos = ft_split(tmp[1], ',');
	cam.pos.x = ft_atof(tmp_pos[0]);
	cam.pos.y = ft_atof(tmp_pos[1]);
	cam.pos.z = ft_atof(tmp_pos[2]);
	tmp_axe = ft_split(tmp[2], ',');
	// On assigne directement à c.forward parce que le vector donné est déjà normalisé
	cam.forward.x = ft_atof(tmp_axe[0]);
	cam.forward.y = ft_atof(tmp_axe[1]);
	cam.forward.z = ft_atof(tmp_axe[2]);
	cam.fov_i = ft_atoi(tmp[3]);
	cam.fov = (ft_atoi(tmp[3])) * (PI / 180);
	free_all(tmp, tmp_pos, tmp_axe, NULL);
	printf("avant cam_init\n");
	//on envoie une référence de c à cam_init pour finir de compléter notre structure
	cam_init(&cam, d->env.size_y / d->env.size_x);
	// printf("cam c.fov: %d\n", cam.fov_i);
	check_cam(cam, d);
	d->cam = cam;
}
