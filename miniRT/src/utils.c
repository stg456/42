/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/19 17:23:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	pass(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i])
			i++;
	}
	return (' ');
}
