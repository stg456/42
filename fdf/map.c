/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/24 16:51:13 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char *map)
{
	char	*str;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0); 
	str = get_next_line(fd);	
	return (str);
}




//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

