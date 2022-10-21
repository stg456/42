/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/10/21 12:40:03 by stgerard         ###   ########.fr       */
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
	t_philo		philo;
	// t_chrono	chrono;
	// int			i;

	// philo = malloc(sizeof(t_philo) * philo.nb_philo);
	// if (philo == NULL)
	// 	ft_error("le malloc de philo qui deconne");
	
	init_arg(argc, argv, philo);

	init_mutex(philo);
	init_thread(philo);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
