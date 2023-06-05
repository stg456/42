/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/05 11:12:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgbinrange(int nb)
{
	if (nb < 0 || nb > 255)
		ft_error("incorrect color");
	return 0;
}

int	vectinrange(float nb)
{
	if (nb < -1 || nb > 1)
		ft_error("incorect vector");
	return 0;
}

int	ratioinrange(float nb)
{
	if (nb < 0 || nb > 1)
		ft_error("incorect ratio");
	return 0;
}