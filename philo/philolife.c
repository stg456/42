/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/06 14:23:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int id)
{
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[philo->rules.nb_philo - 1]);
	else
		pthread_mutex_lock(&philo->forks[id - 2]);
	if (philo->rules.dead == 0)
	{
		pthread_mutex_lock(&philo->writing);
		ft_print(philo, FORK, id);
		pthread_mutex_unlock(&philo->writing);
	}
	if (id == 1 || id == philo->rules.nb_philo)
		pthread_mutex_lock(&philo->forks[0]);
	else
		pthread_mutex_lock(&philo->forks[id - 1]);
	if (philo->rules.dead == 0)
	{
		pthread_mutex_lock(&philo->writing);
		ft_print(philo, FORK, id);
		pthread_mutex_unlock(&philo->writing);
	}
	if (philo->rules.dead == 0)
	{
		pthread_mutex_lock(&philo->writing);
		ft_print(philo, EAT, id);
		pthread_mutex_unlock(&philo->writing);
	}
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
	// return ;
}

void	sleeping(t_philo *philo, int id)
{
	if (philo->rules.dead == 0)
	{
		pthread_mutex_lock(&philo->writing);
		ft_print(philo, SLEEP, id);
		pthread_mutex_unlock(&philo->writing);
	}
	ft_wait(philo->rules.time_sleep);
	// return ;
}
