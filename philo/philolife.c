/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/28 15:00:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_rules rules, t_philo *philo)
{
	pthread_mutex_lock(&(philo->forks)[philo->id - 1]);
	pthread_mutex_lock(&(philo->forks)[philo->id]);
	// timestamp
	// print eat

	usleep(rules.time_eat * 1000);

	pthread_mutex_unlock(&(philo->forks)[philo->id - 1]);
	pthread_mutex_unlock(&(philo->forks)[philo->id]);
	sleeping(rules);
}

void	sleeping(t_rules rules)
{
	// timestamp
	// print sleep
	usleep(rules.time_sleep * 1000);

	// print think
	// timestamp
	// attendre eat
}


