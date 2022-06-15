/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/14 15:49:12 by stgerard         ###   ########.fr       */
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
	while (line)
	{
		if (*line == '\n')
			j++;
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


//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

