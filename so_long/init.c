/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:21:16 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/04 12:05:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_read(char *filename)
{
	t_map_reader	var;

	var.fd = open(filename, O_RDONLY);
	if (var.fd < 0)
		return (NULL);
	var.i = 0;
	var.buffer = malloc(sizeof(char) * 1);
	if (!var.buffer)
		return (NULL);
	var.buffer[0] = '\0';
	var.temp = var.buffer;
	while (42)
	{
		var.temp = get_next_line(var.fd);
		if (var.temp == NULL)
			break ;
		var.buffer = ft_strjoin(var.buffer, var.temp);
		if (var.buffer == NULL)
			return (NULL);
		free(var.temp);
	}
	var.arr = ft_split(var.buffer, '\n');
	free(var.buffer);
	close(var.fd);
	return (var.arr);
}

char	**init_map(char **argv, t_env *e)
{
	// e->mlx = NULL;
	// e->map = NULL;
	// if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	// 	ft_error("\x1B[31mError: map has to be .ber\n");
	// fd = open(argv[1], O_RDONLY);
	// if (fd < 0)
	// 	ft_error("\x1B[31mInvalid map\n");
	e->map = map_read(argv[1]);
	check(e);
	// close(fd);
	return (e->map);
}
