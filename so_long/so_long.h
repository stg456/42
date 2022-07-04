/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:22:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/04 17:10:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <sys/types.h>
# include "./libft/libft.h"
# define BUFFER_SIZE 10000

# define IMG_W 64
# define IMG_H 64

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// struct read

typedef struct s_map_reader
{
	char	**arr;
	char	*buffer;
	char	*temp;
	int		fd;
	int		i;
}				t_map_reader;

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*floor;
}				t_img;

// struct mlx et window
typedef struct s_env
{
	void	*mlx;
	char	**map;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_img	visu;
}				t_env;

// initilisation

void	ft_error(char *str);
int		check(t_env *e);
void	ft_size_win(t_env *e);
char	**init_map(char **argv, t_env *e);
int		key_hook(int key, t_env *e);
int		close_hook(t_env *e);

// getion image

void	init_visu(t_env *e);
void	*xpm_to_img(t_env *data, char *path);
int		build(t_env *e);

#endif