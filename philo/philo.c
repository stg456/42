/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/23 10:59:14 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(t_philo *philo)
{
	int	i;

	i = 0;
	printf("debut routine.\n");
	while (philo->id <= philo->rul->nb_philo)
	{
		pthread_mutex_lock(&(philo->forks)[i - 1]);
		pthread_mutex_lock(&(philo->forks)[i]);
		
		// timestamp
		// print eating
		// usleep
		// timestamp
		

		// si fork 1 et 2 > eat
		// mutex lock
		// tmps eat ft_wait 
		// fin eat 
		// mutex unlock


		// pthread_mutex_lock(&philo);
		// if (philo.forks[i] & philo.forks[i + 1])
		// {
		// 	pthread_mutex_lock(&philo);
		// 	philo.forks[i];

		// 	// time
		// 	printf("philo %d ", philo.id);
		// 	pthread_mutex_unlock(&philo);
		// }

		pthread_mutex_unlock(&(philo->forks)[i - 1]);
		pthread_mutex_unlock(&(philo->forks)[i]);
	}
	printf("fin routine.\n");
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	// t_rules		rules;
	// t_chrono	*chrono;

	philo = NULL;
	init_arg(argc, argv);
	init_mutex(philo);
	init_thread(philo);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
