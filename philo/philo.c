/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/29 17:53:34 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(t_philo philo)
{
	int	i;

	i = 0;
	printf("debut routine.\n");
	while (philo.id <= philo.nb_philo)
	{
		pthread_mutex_lock(&philo);
		if (philo.id[i] & philo.id[i + 1])
		{
			pthread_mutex_lock(&philo);
			philo.id[i];

			// time
			printf("philo %d ", philo.id);
			pthread_mutex_unlock(&philo);
		}
	}
	// usleep(1000);
	printf("fin routine.\n");
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_chrono	chrono;
	// t_arg		param;
	int			i;

	// philo = malloc(sizeof(t_philo));
	// if (philo == NULL)
	// 	exit(EXIT_FAILURE);
	

	init_arg(argc, argv, philo);
	// if (param.nb_philo = 1)
	// {
	// 	philo_dead();
	// }
	init_mutex(philo);
	init_thread(philo);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
