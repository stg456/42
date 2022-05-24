/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:46:38 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/24 16:25:47 by stgerard         ###   ########.fr       */
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
# define BUFFER_SIZE 300

// struct mlx et window
typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		color;
}				t_env;

// initilisation

//int		read_map(char *map);
char	*read_map(char *map);

// utils
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif