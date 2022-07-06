/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:22:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/06 16:48:07 by stgerard         ###   ########.fr       */
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
// # define BUFFER_SIZE 10000

# define T_S 63

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
}			t_map_reader;

typedef struct s_sprite
{
	struct s_sprite		*head;
	void				*img;
	struct s_sprite		*next;
}		t_sprite;

typedef struct s_img
{
	void		*player;
	void		*wall;
	void		*collectible;
	void		*exit;
	void		*exitc;
	void		*floor;
	void		*enemy;
	t_sprite	*health;
	t_sprite	*key;
}			t_img;

typedef struct s_pos
{
	ssize_t	x;
	ssize_t	y;
}			t_pos;

typedef struct s_check
{
	size_t	i;
	size_t	j;
	int		n_c;
	int		n_e;
	int		n_p;
}			t_check;

// struct mlx et window

typedef struct s_env
{
	void	*mlx;
	char	**map;
	void	*win;
	size_t	size_x;
	size_t	size_y;
	int		p_x;
	int		p_y;
	int		collectible;
	t_img	visu;
	int		steps;
	int		health;
}				t_env;

// initilisation

void	ft_error(char *str);
int		check(t_env *e);
void	ft_size_win(t_env *e);
void	init_game(t_env *e);
char	**init_map(char **argv, t_env *e);
int		key_hook(int key, t_env *e);
int		close_hook(t_env *e);

// getion image

void	init_visu(t_env *e);
void	*xpm_to_img(t_env *data, char *path);
void	img_to_sprite(t_env *e, t_sprite **sprite, char *img, int c);
void	build(t_env *e);
void	move(int key, t_env *e);
int		loop_hook(t_env *e);
void	put_mlx(t_env *e, void *img, int x, int y);
void	refresh_tiles(t_env *e, t_pos p);
void	refresh_collectible(t_env *e, t_pos p);
void	refresh_exit(t_env *e, t_pos p);
void	refresh_walls(t_env *e, t_pos p);
void	refresh_enemy(t_env *e, t_pos p);

#endif