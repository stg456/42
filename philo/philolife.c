/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:26:24 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 14:13:21 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, size_t id)
{
	pthread_mutex_lock(&philo->forks[id - 1]);
	ft_print(philo, FORK, id);
	pthread_mutex_lock(&philo->forks[id % philo->rules.nb_philo]);
	ft_print(philo, FORK, id);
	philo->lunch_time[id - 1] = diff_chrono(philo);
	ft_print(philo, EAT, id);
	usleep(philo->rules.time_eat * 1000);
	pthread_mutex_unlock(&philo->forks[id - 1]);
	pthread_mutex_unlock(&philo->forks[id % philo->rules.nb_philo]);
}

void	sleeping(t_philo *philo, size_t id)
{
	ft_print(philo, SLEEP, id);
	usleep(philo->rules.time_sleep * 1000);
}

void	ft_print(t_philo *philo, int msg, int id)
{
	pthread_mutex_lock(&philo->writing);
	if (msg == FORK)
		printf("\x1B[35m%lli %i has taken a fork\x1B[0m\n", diff_chrono(philo), id);
	else if (msg == EAT)
		printf("\x1B[32m%lli %i is eating\x1B[0m\n", diff_chrono(philo), id);
	else if (msg == SLEEP)
		printf("\x1B[36m%lli %i is sleeping\x1B[0m\n", diff_chrono(philo), id);
	else if (msg == THINK)
		printf("\x1B[33m%lli %i is thinking\x1B[0m\n", diff_chrono(philo), id);
	pthread_mutex_unlock(&philo->writing);
}
