/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:42:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/18 17:44:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char **argv)
{
	int		fd;
	char	*line;
	t_env	e;
	int		**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	e.x = 10;
	e.y = 10;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	//line = ft_calloc(sizeof(char *) * 1000001);//malloc
	line = get_next_line(fd);
	map = (int **)malloc(sizeof(int *) * );//malloc
	while (line[k] != '\0')
	{
		if (line[k] == ' ')
			i++;
		else if (line[k] == '\n')
			j++;
		else
		{
			map[j][i] = ft_atoi(line);
			mlx_pixel_put(e.mlx, e.win, e.x, e.y, 0xffffffff);
			//draw_map(map);
			e.x += 5;
			e.y += 5;
		}
	}
	return (0);
}