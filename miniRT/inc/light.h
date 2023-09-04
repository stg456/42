/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:54 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 16:22:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_amb
{
	int			nbA;
	float		ratio;
	int			rgb;
}				t_amb;

typedef struct s_lum
{
	int			nbL;
	t_vec		pos;
	float		ratio;
	int			rgb;
}				t_lum;

#endif