/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:16:45 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 16:17:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_cam
{
	t_vec		pos;
	t_vec		forward;
	t_vec		up;
	t_vec		right;
	float		h;
	float		w;
	float		fov;
}				t_cam;

void	cam_init(t_cam *c, float aspect_ratio);

t_ray	make_ray(t_cam *c, t_vec2 point);

#endif
