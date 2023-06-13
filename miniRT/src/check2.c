/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:24:18 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/13 16:05:57 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_amb(t_amb a)
{
	printf("check2 a.rgb.b: %d\n", a.rgb.b);
	if (rgbinrange(a.rgb.r) || rgbinrange(a.rgb.g) || rgbinrange(a.rgb.b)
	|| ft_isdigit(a.rgb.r) || ft_isdigit(a.rgb.g) || ft_isdigit(a.rgb.b))
		ft_error("Error\nincorrect rgb value for A\n");
	printf("check2b a.rgb.b: %d\n", a.rgb.b);
	printf("rgbinrange(a.rgb.b): %d\n", rgbinrange(a.rgb.b));
} // ne marche pas