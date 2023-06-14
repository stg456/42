/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/14 11:07:44 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	load_data2(char *buf, t_data d)
{
	if (*buf != '\0'/* && *buf != '\n'*/)
	{
		if (*buf == ' ' || *buf == '\t')
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
		{
			// pass(buf);
			cyl(buf, d);
		}
		else
		{
			printf("buf: %s", buf);
			ft_error("Error:\nincorrect data\n");
		}
	}
	return (d);
}

int	load_data(t_env e, t_data d, char **av)
{
	(void) e;
	int		fd;
	char	*buf;

	d.nbA = 0;
	d.nbC = 0;
	d.nbcy = 0;
	d.nbL = 0;
	d.nbpl = 0;
	d.nbsp = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("\x1B[31mError\nInvalid file\n");
	}
	buf = get_next_line(fd);
	if (!buf)
		ft_error("Error\nfile is empty\n");
	while (buf)
	{
		d = load_data2(buf, d);
		free(buf);
		buf = NULL;
		buf = get_next_line(fd);
	}
	close(fd);
	return (0);
}
