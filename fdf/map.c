/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/31 13:06:34 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char *map)
{
	int		fd;
	char	*line;
	t_env	e;
	int		interv;

	interv = 20;
	e.x = 10;
	e.y = 10;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line,(fd, &line) == 1)
	{
		while (*line != '\0')
		{
			if (*line == ' ')
				line++;
			else
			{
				e.z = atoi(&line);/*error*/
				

			}
		}
	}

	return (map);
}


//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

