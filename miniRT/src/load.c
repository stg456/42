/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/01 11:46:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	load_data2(char *buf, t_data *d)
{
	if (*buf != '\0')
	{
		if (*buf == '\n')
		{};
		if (ft_strncmp(buf, "A", 1) == 0)
			amb(buf, d);
		else if (ft_strncmp(buf, "C", 1) == 0)
			cam(buf, d);
		else if (ft_strncmp(buf, "L", 1) == 0)
			lum(buf, d);
		else if (ft_strncmp(buf, "sp", 2) == 0)
			sp(buf, d);
		else if (ft_strncmp(buf, "pl", 2) == 0)
			pl(buf, d);
		else if (ft_strncmp(buf, "cy", 2) == 0)
			cyl(buf, d);
		else
		{
			printf("buf: %s", buf);
			close(d->fd);
			ft_error("Error:\nincorrect data\n");
		}
	}
}

void	load_data(t_data *d, char *filename)
{
	char	*buf;

	d->fd = open(filename, O_RDONLY);
	if (d->fd < 0)
	{
		close(d->fd);
		ft_error("\x1B[31mError\nInvalid file\n");
	}
	buf = get_next_line(d->fd);
	if (!buf)
		ft_error("Error\nfile is empty\n");
	while (buf)
	{
		load_data2(buf, d);
		free(buf);
		buf = NULL;
		buf = get_next_line(d->fd);
	}
	close(d->fd);
}

void	memory_alloc(t_data *d)
{
	if (d->nbsp > 0)
	{
		d->shapes.spheres = malloc(sizeof(t_sphere) * d->nbsp);
		if (!d->shapes.spheres)
			ft_error("Error:\nSphere Malloc Error\n");
	}
	if (d->nbpl > 0)
	{
		d->shapes.planes = malloc(sizeof(t_plane) * d->nbpl);
		if (!d->shapes.planes)
			ft_error("Error:\nPlane Malloc Error\n");
	}
	if (d->nbcy > 0)
	{
		d->shapes.cylindres = malloc(sizeof(t_cyl) * d->nbcy);
		if (!d->shapes.cylindres)
			ft_error("Error:\nCylindre Malloc Error\n");
	}
	d->shapes.sphere_nb = d->nbsp;
	d->shapes.plane_nb = d->nbpl;
	d->shapes.cyl_nb = d->nbcy;
}