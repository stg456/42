/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:21:16 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/27 13:46:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*init_map(char **argv, t_env *e)
{
	int	fd;

	e->mlx = NULL;
	e->map = NULL;
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error("\x1B[31mError\nmap has to be .ber\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("\x1B[31mInvalid map\n");
	e->map = get_next_line(fd);
	check(e);	
	return (e->map);
}

void	ft_size_win(t_env *e, char **argv)
{
	int	fd;

	e->size_x = (ft_line_length(fd) * IMG_W);
	e->size_y = (ft_count_lines(fd, e->size_x, IMG_W) * IMG_H);
}