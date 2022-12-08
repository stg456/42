/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:52:52 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 14:23:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->writing);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	pthread_mutex_unlock(&ph->writing);
}

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->writing);
	printf("\x1B[34m%lld philo %i ", chrono(*ph), ph->id + 1);
	printf(" has taken a fork\n\x1B[0m");
	pthread_mutex_unlock(&ph->writing);
}

void	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->writing);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	pthread_mutex_unlock(&ph->writing);
}

void	died(t_philo *ph)
{
	pthread_mutex_lock(&ph->writing);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", chrono(*ph), ph->id + 1);
	pthread_mutex_unlock(&ph->writing);
}
