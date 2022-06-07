/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/07 12:28:16 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char **argv)
{
	int		fd;
	char	*line;
	t_env	e;
	int		interv;
	char	**map;
	int		i;
	int		j;

	interv = 20;
	e.x = 10;
	e.y = 10;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	map = get_next_line(fd);

	while (get_next_line(fd, &line) == 1)
	{
		if (*line != '\n')

		elseif (*line == ' ')
				line++;
		else
		{
			map[i][j] = ft_split(*line, ' ');
			e.z = atoi(&line);/*error*/
				
			
			
		}
	}
	//map = split et join
	return (map);
}


//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

