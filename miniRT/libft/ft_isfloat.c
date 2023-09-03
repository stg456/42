/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:31:59 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/03 17:47:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isfloat2(const char *str)
{
	int	pointcount;

	pointcount = 0;
	if (*str == '.')
	{
		pointcount++;
		if (pointcount > 1)
			return (1);
		str++;
	}
	return (0);
}

int	ft_isfloat(const char *str)
{
	int	pointcount;
	int	signcount;
	int	i;

	pointcount = 0;
	i = 0;
	signcount = 0;
	while (str[i] != '\0')
	{
		ft_isfloat2(str);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+' && i != 0)
			return (1);
		else if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (1);
		else if ((str[i] == '-' || str[i] == '+') && i == 0)
			signcount++;
		else if (signcount > 1)
		i++;
	}
	if (str[ft_strlen(str) - 1] == '.')
		return (1);
	return (0);
}
