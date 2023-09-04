/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:52 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/04 17:44:39 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_amb
{
	int			nb_a;
	float		ratio;
	int			rgb;
}				t_amb;

typedef struct s_lum
{
	int			nb_l;
	t_vec		pos;
	float		ratio;
	int			rgb;
}				t_lum;

#endif