/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:22:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/21 14:24:10 by stgerard         ###   ########.fr       */
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
# define BUFFER_SIZE 3000

# define IMG_W 64
# define IMG_H 64

// struct mlx et window
typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_env;

// initilisation

void	ft_size_win(t_env *e, char **argv);
void	ft_init(t_map map, t_env e);
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