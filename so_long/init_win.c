/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:39:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/20 17:20:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_size_win(char **argv, t_env *e)
{
	int		fd;
	t_env	e;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		perror("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	//e.size_x = (ft_line_length(fd) * IMG_W);
	//e.size_y = (ft_count_lines(fd, e.size_x, IMG_W) * IMG_H);
}