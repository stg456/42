/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:08 by stgerard          #+#    #+#             */
/*   Updated: 2023/03/16 18:16:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**map_read(char *filename)
{
	int		fd;
	int		i;
	char	*buf;
	char	*tmp;
	char	**arr;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	tmp = buf;
	while (42)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		buf = strjoin(buf, tmp);
		if (buf == NULL)
			return (NULL);
		free(tmp);
	}
	arr = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (arr);
}

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

