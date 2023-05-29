/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:08:08 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/29 18:05:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_read(char *filename)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	m->i = 0;
	m->fd = open(filename, O_RDONLY);
	printf("c: %d\n", m->fd);
	if (m->fd < 0)
		return (NULL);
	m->buf = malloc(sizeof(char) * 1);
	if (!m->buf)
		return (NULL);
	m->buf[0] = '\0';
	// printf("%s\n", m->buf);
	// m->tmp = m->buf;
	// while (42)
	// {
	// 	m->tmp = get_next_line(m->fd);
	// 	printf("%s\n", m->tmp);
	// 	if (m->tmp == NULL)
	// 		break ;
	// 	m->buf = strjoin(m->buf, m->tmp);
	// 	if (m->buf == NULL)
	// 		return (NULL);
	// 	free(m->tmp);
	// }
	// m->arr = ft_split(m->buf, '\n');
	// printf("%s\n", m->arr);
	free(m->buf);
	close(m->fd);
	free(m);
	return (m->arr);
}

char	**init_map(char **av, t_env *e)
{
	(void)av;
	t_map	*m;
	
	m = malloc(sizeof(t_map));
	e->mlx = NULL;
	e->map = NULL;
	m->fd = 0;

	if (ft_strnstr(av[1], ".cub", ft_strlen(av[1])) == NULL)
		ft_error("\x1B[31mError\nmap has to be .cub\n");

	printf("%s\n", av[1]);
	m->fd = open(av[1], O_RDONLY);
	printf("fd: %d\n", m->fd);
	if (m->fd < 0)
	{
		close(m->fd);
		ft_error("\x1B[31mError\nInvalid map\n");
	}
	// printf("%s\n", m->arr);
	// e->map = map_read(av[1]);
	// check(e);
	close(m->fd);
	free(m);
	return (e->map);
}
