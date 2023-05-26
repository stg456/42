/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/26 12:14:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <sys/types.h>

#define PI 3.14159

typedef struct s_map
{
	char	**arr;
	char	*buffer;
	char	*temp;
	int		fd;
	int		i;
}			t_map;

typedef struct s_env
{
	mlx_t	*mlx;
	char	**map;
	void	*win;
	size_t	size_x;
	size_t	size_y;
	mlx_image_t	*img;

}				t_env;

// main.c

int		main(int ac, char **av);
void	keyhook(mlx_key_data_t keydata, void* param);
void	ft_error(char *str);
int		close_hook(t_env *e);

// init.c

char	**init_map(char **argv, t_env *e);
char	**map_read(char *filename);

#endif