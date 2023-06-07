/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:05 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/07 16:31:29 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	load_data2(t_env e, t_data d, char **av)
{
	// int i;

	// i = 0;
	// while ()



	// return (d);
}

int	load_data(t_env e, t_data d, char **av)
{
	int		fd;
	char	*buf;
	(void)e;

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
	while (*buf != '\0')
	{
		while (*buf != '\n')
		{
			while (*buf == ' ')
				buf++;
			if (strcmp(*buf, "A") == 0)
				amb();
			else if (strcmp(*buf, "C") == 0)
				cam();
			else if (strcmp(*buf, "L") == 0)
				lum();
			else if (strcmp(*buf, "sp") == 0)
				sp();
			else if (strcmp(*buf, "pl") == 0)
				pl();
			else if (strcmp(*buf, "cy") == 0)
				cyl();
			else
				ft_error("Error:\nincorrect data\n");
		}
	}
	// d = load_data2(e, d, av);
	printf("a donf\n");

	close(fd);
	return 0;
}