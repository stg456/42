/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/01 16:17:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int id)
{
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[philo->rules.nb_philo - 1]);
	else
		pthread_mutex_lock(&philo->forks[id - 2]);
	ft_print(philo, FORK);
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[0]);
	else
		pthread_mutex_lock(&philo->forks[id - 1]);
	ft_print(philo, FORK);
	ft_print(philo, EAT);
	philo->lunch_time[id - 1] = diff_chrono(*philo);
	usleep(philo->rules.time_eat * 1000);
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

void	sleeping(t_philo *philo)
{
	ft_print(philo, SLEEP);
	usleep(philo->rules.time_sleep * 1000);
}
