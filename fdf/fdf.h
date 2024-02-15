/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:46:38 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/19 12:04:29 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include "./libft/libft.h"
# define BUFFER_SIZE 3000

// struct mlx et window
typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		nbline;
	int		x;
	int		y;
	int		z;
	int		**map;
}				t_env;

typedef struct s_draw
{
	int		startx;
	int		starty;
	int		endxx;
	int		endxy;
	int		endyx;
	int		endyy;
}				t_draw;

// initilisation

int		read_map(char **argv);
int		draw_map(int **map);

// utils
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
//char	*ft_strchr(char *s, int c);
//char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif