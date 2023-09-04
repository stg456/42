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
	if (fovinrange(c.fov))
	{
		close(d->fd);
		ft_error("Error\nFOV of camera not in the range\n");
	}
}

void	cam(char *buf, t_data *d)
{
	t_cam	cam;
	char	**tmp;
	char	**tmp_pos;
	char	**tmp_axe;

	tmp = ft_split(buf, ' ');
	if (split_count(tmp) != 4)
		ft_error("Invalid cam data\n");
	tmp_pos = ft_split(tmp[1], ',');
	check_pos(d, tmp_pos);
	cam.pos = get_coor(tmp_pos);
	tmp_axe = ft_split(tmp[2], ',');
	vectinrange(d, tmp_axe);
	cam.forward = get_coor(tmp_axe);
	normalize(&cam.forward);
	cam.fov = ft_atoi(tmp[3]);
	check_cam(cam, d);
	cam.fov = (ft_atoi(tmp[3])) * (PI / 360);
	free_all(tmp, tmp_pos, tmp_axe, NULL);
	cam_init(&cam, d->env.size_y / d->env.size_x);
	d->cam = cam;
}
