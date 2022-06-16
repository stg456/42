/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:42:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 14:42:24 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char **argv)
{
	int		fd;
	char	*line;
	int		nbline;
	char	*mapjoin;
	t_env	e;
	int		interv;
	int		**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	interv = 20;
	e.x = 10;
	e.y = 10;
	nbline = 0;
	mapjoin = "\0";
	e.nbline = 0;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line[i])
	{
		if (line[i] == '\n')
		{

			map = malloc(sizeof(int *) * e.nbline);
			j++;
		}
		else if (*line == ' ')
			i++;
		else
		{
			map[j][i] = ft_atoi(&line);
			mlx_pixel_put(e.mlx, e.win, e.x, e.y, 0x80eaeaea);
			e.x += 5;
			e.y += 5;
		}
	}


	return (0);
}