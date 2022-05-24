/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:01:07 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/24 14:23:50 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_map(char *map)
{
	char	*str;
	int		fd;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	
	return (fd);
}




//uint	mlx_get_color_value(void *mlx_ptr, int color);

//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

