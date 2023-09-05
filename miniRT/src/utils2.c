/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:13:02 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 15:13:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	sqr(float f)
{
	return (f * f);
}

int	get_color(char **split)
{
	int	res;
	int	color;
	int	i;

	i = 0;
	res = 0;
	while (i < 3)
	{
		if (!ft_isint(split[i]))
			ft_error("Error\nRGB value is invalid\n");
		color = ft_atoi(split[i]);
		if (!ft_isrgb(color))
			ft_error("Error\nRGB value not in range\n");
		res = (res << 8) | color;
		i++;
	}
	res = (res << 8) | 255;
	return (res);
}
