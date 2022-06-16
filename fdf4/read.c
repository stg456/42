/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:43:51 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 15:56:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_point(char **line, t_env *e, int *x, int y)
{
	int		z;

	z = ft_atoi(*line);
	new_point(*x, y, z, e);
	if (z < e->min_z)
		e->min_z = z;
	if (z > e->max_z)
		e->max_z = z;
	if (z < 0)
	{
		(*line)++;
		z = -z;
	}
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
	*x -= 1;
	(*line)++;
}

int		open_file(t_env *e, char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, e));
}

int		read_file(int fd, t_env *e)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		while (*line != '\0')
		{
			if (*line == ' ')
				line++;
			else
			{
				if (*line != '-' && (*line < '0' || *line > '9'))
					return (0);
				read_point(&line, e, &x, y);
			}
		}
		end_point(e);
		y -= 1;
	}
	e->max_x = -x;
	e->max_y = -y;
	return (1);
}