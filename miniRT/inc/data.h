/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:48 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 14:57:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	int			fd;
	mlx_image_t	*img;
	t_cam		cam;
	t_shape		shapes;
	t_amb		amb;
	t_lum		lum;
	t_env		env;
}				t_data;

#endif