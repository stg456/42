/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:41 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/02 16:27:35 by stgerard         ###   ########.fr       */
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
	printf("%s\n", str);
	return ;
}

void	ft_print(t_philo *philo, int msg, int id)
{
	pthread_mutex_lock(&philo->writing);
	if (msg == 0)
		printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", diff_chrono(*philo), id);
	else if (msg == 1)
		printf("\x1B[32m%lld philo %i is eating\n\x1B[0m", diff_chrono(*philo), id);
	else if (msg == 2)
		printf("\x1B[33m%lld philo %i is sleeping\n\x1B[0m", diff_chrono(*philo), id);
	else if (msg == 3)
		printf("\x1B[36m%lld philo %i is thinking\n\x1B[0m", diff_chrono(*philo), id);
	else if (msg == 4)
	{
		printf("\x1B[31m%lld philo %i died\n\x1B[0m", diff_chrono(*philo), id);
		closephilo(philo);
	}
	if (philo->rules.dead == 0)
		pthread_mutex_unlock(&philo->writing);
	else
		pthread_mutex_unlock(&philo->dead);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isdigit_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (1);
		}
		++i;
	}
	return (0);
}
