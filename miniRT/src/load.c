/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/08 16:28:17 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	load_data2(char *buf, t_data d)
{
	while (*buf != '\0')
	{
		while (*buf != '\n')
		{
			if (*buf == ' ' || *buf == '\t')
				buf++;
			if (ft_strncmp(buf, "A", 1) == 0)
				amb(buf, d);
			// else if (ft_strcmp(*buf, "C") == 0)
			// 	cam();
			// else if (ft_strcmp(*buf, "L") == 0)
			// 	lum();
			// else if (ft_strcmp(*buf, "sp") == 0)
			// 	sp();
			// else if (ft_strcmp(*buf, "pl") == 0)
			// 	pl();
			// else if (ft_strcmp(*buf, "cy") == 0)
			// 	cyl();
			else
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
	d = load_data2(buf, d);

	close(fd);
	return (0);
}
