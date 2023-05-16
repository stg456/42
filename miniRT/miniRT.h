/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:00 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/16 17:34:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

# define T_S 63

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;

typedef struct s_data
{
	char	*buf;
	char	*tmp;
	int		fd;
	int		i;

}				t_data;

#endif