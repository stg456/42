/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:08 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/16 17:50:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**init_map(char **argv, t_env *e)
{
	int	fd;

	e->mlx = NULL;
	e->map = NULL;
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		ft_error("\x1B[31mError: map has to be .cub\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("\x1B[31mInvalid map\n");
	}
	e->map = map_read(argv[1]);
	check(e);
	close(fd);
	return (e->map);
}

