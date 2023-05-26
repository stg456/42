/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:08 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/26 13:58:07 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**map_read(char *filename)
// {
// 	int		fd;
// 	int		i;
// 	char	*buf;
// 	char	*tmp;
// 	char	**arr;

// 	i = 0;
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	buf = malloc(sizeof(char) * 1);
// 	if (!buf)
// 		return (NULL);
// 	buf[0] = '\0';
// 	tmp = buf;
// 	while (42)
// 	{
// 		tmp = get_next_line(fd);
// 		if (tmp == NULL)
// 			break ;
// 		buf = strjoin(buf, tmp);
// 		if (buf == NULL)
// 			return (NULL);
// 		free(tmp);
// 	}
// 	arr = ft_split(buf, '\n');
// 	free(buf);
// 	close(fd);
// 	return (arr);
// }

char	**init_map(char **av, t_env *e)
{
	// (void)av;
	t_map	*m;
	
	m = malloc(sizeof(t_map));
	e->mlx = NULL;
	e->map = NULL;
	if (ft_strnstr(av[1], ".cub", ft_strlen(av[1])) == NULL)
		ft_error("\x1B[31mError: map has to be .cub\n");
	m->fd = open(av[1], O_RDONLY);
	if (m->fd < 0)
	{
		close(m->fd);
		ft_error("\x1B[31mInvalid map\n");
	}
	e->map = map_read(av[1]);
	// check(e);
	close(m->fd);
	free(m);
	return (e->map);
}
