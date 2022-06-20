/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:39:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/20 18:26:44 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_size_win(t_env *e, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("\x1B[31mError\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		perror("\x1B[31mError\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	//e.size_x = (ft_line_length(fd) * IMG_W);
	//e.size_y = (ft_count_lines(fd, e.size_x, IMG_W) * IMG_H);
}