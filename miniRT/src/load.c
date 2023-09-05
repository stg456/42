/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 09:48:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	load_data2(char *buf, t_data *d)
{
	if (*buf != '\0')
	{
		while (*buf == ' ' || *buf == '\t')
			buf++;
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
		if (*buf != '\n' && *buf != '\r')
			load_data2(buf, d);
		free(buf);
		buf = NULL;
		buf = get_next_line(d->fd);
	}
	close(d->fd);
}
