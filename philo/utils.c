/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/22 15:14:37 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			n;
	long int	j;

	i = 0;
	j = 0;
	n = 1;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (j * n > 2147483647)
			return (-1);
		else if (j * n < -2147483648)
			return (0);
		j = (str[i] - '0') + (j * 10);
		i++;
	}
	return (j * n);
}

void	ft_error(char *str)
{
	printf(str);
	exit(EXIT_FAILURE);
}

void	ft_print(char *str)
{

}

void	ft_wait()
{

}
