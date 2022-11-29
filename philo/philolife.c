/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 16:22:34 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->forks)[philo->id - 1]);
	pthread_mutex_lock(&(philo->forks)[philo->id]);
	// timestamp
	ft_print(philo, "FORK");
	ft_print(philo, "EAT");
	// print eat

	usleep(philo->rules.time_eat * 1000);

	pthread_mutex_unlock(&(philo->forks)[philo->id - 1]);
	pthread_mutex_unlock(&(philo->forks)[philo->id]);
	sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	// timestamp
	// print sleep
	ft_print(philo, "SLEEP");
	usleep(philo->rules.time_sleep * 1000);

	// print think
	ft_print(philo, "THINK");
	// timestamp
	// attendre eat
}


