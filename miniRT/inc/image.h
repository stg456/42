/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:41:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 17:42:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_data	t_data;

uint32_t	*get_pixel(mlx_image_t *img, int x, int y);

void		save_img(mlx_image_t *img, char *filename);

// void		ray_trace(void *param);
void		ray_trace(t_data *d);

#endif