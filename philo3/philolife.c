/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/07 13:46:10 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int id)
{
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[philo->rules.nb_philo - 1]);
	else
		pthread_mutex_lock(&philo->forks[id - 2]);
	pthread_mutex_lock(&philo->writing);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", diff_chrono(*philo), id);
	// ft_print(philo, FORK, id);
	pthread_mutex_unlock(&philo->writing);
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[0]);
	else
		pthread_mutex_lock(&philo->forks[id - 1]);
	pthread_mutex_lock(&philo->writing);
	printf("\x1B[34m%lld philo %i has taken a fork\n\x1B[0m", diff_chrono(*philo), id);
	// ft_print(philo, FORK, id);
	pthread_mutex_unlock(&philo->writing);
	printf("\x1B[32m%lld philo %i is eating\n\x1B[0m", diff_chrono(*philo), id);
	pthread_mutex_lock(&philo->writing);
	// ft_print(philo, EAT, id);
	pthread_mutex_unlock(&philo->writing);
	philo->lunch_time[id - 1] = diff_chrono(*philo);
	ft_wait(philo->rules.time_eat);
	if (id == 1 || id == philo->rules.nb_philo)
	{
		pthread_mutex_unlock(&philo->forks[philo->rules.nb_philo - 1]);
		pthread_mutex_unlock(&philo->forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[id - 2]);
		pthread_mutex_unlock(&philo->forks[id - 1]);
	}
}

void	sleeping(t_philo *philo, int id)
{
	if (philo->rules.dead == 0)
	{
		pthread_mutex_lock(&philo->writing);
		printf("\x1B[33m%lld philo %i is sleeping\n\x1B[0m", diff_chrono(*philo), id);
		// ft_print(philo, SLEEP, id);
		pthread_mutex_unlock(&philo->writing);
	}
	ft_wait(philo->rules.time_sleep);
}
