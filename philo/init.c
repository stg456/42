/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:28 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 17:46:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(int argc, char **argv, t_philo *philo)
{
	philo->id = 1;
	if (argc < 5 || argc > 6)
		ft_error("REDError : Bad numbers of arguments.\n");
	philo->rules.nb_philo = ft_atoi(argv[1]);
	philo->rules.time_die = ft_atoi(argv[2]);  
	philo->rules.time_eat = ft_atoi(argv[3]);
	philo->rules.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->rules.nb_eat = ft_atoi(argv[5]);
	philo->rules.runtime = timestamp();
	philo->rules.dead = 0;
	if (philo->rules.nb_philo == 1)
		philo->rules.dead = 1;
	philo->lunch_time = malloc(sizeof(int) * philo->rules.nb_philo);
	if (philo->lunch_time == NULL)
		return (1);
	memset(philo->lunch_time, 0, sizeof(int) * philo->rules.nb_philo);
	return (0);
}

int	init_mutex(t_philo *philo)
{
	size_t	i;

	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->rules.nb_philo);
	pthread_mutex_init(&philo->writing, NULL);
	if (philo->forks == NULL)
	{
		printf("Mutex malloc error\n");
		return (1);
	}
	i = 0;
	// printf("Avant la création des mutex.\n");
	while ((int)i < philo->rules.nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		++i;
	}
	// printf("apres la création des mutex pour les forks.\n");
	return (0);
}

int	init_thread(t_philo *philo)
{
	size_t	i;

	i = 0;
	philo->threads = malloc(sizeof(pthread_t) * philo->rules.nb_philo);
	if (philo->threads == NULL)
	{
		printf("Pthread malloc error\n");
		return (1);
	}
	// printf("Avant la création des threads.\n");
	while ((int)i < philo->rules.nb_philo)
	{
		pthread_create(&philo->threads[i], 0, &gestphilo, philo);
		pthread_detach(philo->threads[i]);
		if (i % 2 == 0)
			usleep(500);
		++philo->id;
		++i;
	}
	// printf("apres la création des threads.\n");
	return (0);
}
