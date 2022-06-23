/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:22:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/23 12:02:39 by stgerard         ###   ########.fr       */
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

// struct mlx et window
typedef struct s_env
{
	void	*mlx;
	char	*map;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;

	int		fd;
	//t_img	*img;
}				t_env;

// counter map
typedef struct s_vstock
{
	char	*tmp;
	int		pcount;
	int		ecount;
	int		ccount;
}				t_vstock;

// initilisation

void	ft_size_win(t_env *e, char **argv);
char	*init_map(char **argv, t_env e);
int		key_hook(int key, t_env *e);
int		close_hook(t_env *e);
//oid	ft_size_win(t_env *e, char **argv);
//void	ft_init(t_map map, t_env e);
//int		read_map(char **argv);
//int		draw_map(int **map);

// utils
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_strchr(char *s, int c);
//char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif