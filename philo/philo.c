/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/11 18:24:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(t_philo philo)
{
	int	i;

	i = 0;
	printf("debut routine.\n");
	while (philo.id <= philo->rul->nb_philo)
	{





		// pthread_mutex_lock(&philo);
		// if (philo.forks[i] & philo.forks[i + 1])
		// {
		// 	pthread_mutex_lock(&philo);
		// 	philo.forks[i];

		// 	// time
		// 	printf("philo %d ", philo.id);
		// 	pthread_mutex_unlock(&philo);
		// }
	}
	// usleep(1000);
	printf("fin routine.\n");
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_rules		*rules;
	// t_chrono	*chrono;

	init_arg(argc, argv, rules);

	init_mutex(philo);
	init_thread(philo);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
