/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/07 15:13:58 by stgerard         ###   ########.fr       */
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
	char	**map;
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
	map[i][j];
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);

	while (line)
	{
		if (*line = '\n')
			j++;
		else if (*line = ' ')
			i++;
		else
		{
			map = ft_split(line, ' ');
			e.z = atoi(&map[i][j]);
				
			
		}
	}


	return (map);
}


//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

