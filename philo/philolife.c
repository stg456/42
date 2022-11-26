/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:14:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/26 17:05:28 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_rules rules, t_philo *philo)
{
	pthread_mutex_lock(&(philo->forks)[i - 1]); // mettre le id de philo
	pthread_mutex_lock(&(philo->forks)[i]);
	// timestamp
	// print eat

	usleep(rules.time_eat * 1000);

	pthread_mutex_unlock(&(philo->forks)[i - 1]);
	pthread_mutex_unlock(&(philo->forks)[i]);
	sleeping(rules);
}

void	sleeping(t_rules rules)
{
	// timestamp
	// print sleep
	usleep(rules.time_sleep * 1000);

	// print think
	// timestamp
}


