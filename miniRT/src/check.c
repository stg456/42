/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:44:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/14 12:12:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgbinrange(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (0);
	else
		return (1);
}

int	vectinrange(double nb)
{
	if (nb < -1 || nb > 1)
		return (1);
	else
		return (0);
}

int	ratioinrange(double nb)
{
	if (nb >= 0 || nb <= 1)
		return (0);
	else
		return (1);
}

int	fovinrange(int nb)
{
	if (nb >= 0 && nb <= 180)
		return (0);
	else
		return (1);
}
