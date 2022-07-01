/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:21:16 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/01 15:03:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*init_map(char **argv, t_env *e)
{
	int	fd;

	e->mlx = NULL;
	e->map = NULL;
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error("\x1B[31mError: map has to be .ber\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("\x1B[31mInvalid map\n");
	e->map = get_next_line(fd);
	check(e);
	return (e->map);
}

// ne sort pas de la boucle
// void	ft_size_win(t_env *e)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	while (e->map[i] != '\n')
// 		i++;
// 	e->size_x = i * IMG_W;
// 	while (e->map[i] != '\0')
// 	{
// 		if (e->map[i] == '\n')
// 			j++;
// 	}
// 	e->size_y = j * IMG_H;
// }

// v2
void	ft_size_win(t_env *e)
{
	char	**tab;
	int	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) + 1);
	while (e->map != NULL)
	{
		
	}
}