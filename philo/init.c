/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:28 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/11 16:24:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(int argc, char **argv, t_philo	philo)
{
	if (argc < 5 || argc > 6)
		ft_error("REDError : Bad numbers of arguments.\n");
	philo.nb_philo = ft_atoi(argv[1]);
	philo.time_die = ft_atoi(argv[2]);
	philo.time_eat = ft_atoi(argv[3]);
	philo.time_sleep = ft_atoi(argv[4]);
	if (argc == 6) 
		philo.nb_eat = ft_atoi(argv[5]);
}

void	init_mutex(t_philo philo)
{
	int	i;

	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
	if (philo.forks == NULL)
		ft_error("REDle malloc des fork qui deconne");
	i = philo.nb_philo;
	printf("Avant la création des mutex.\n");
	while (i--)
	{
		pthread_mutex_init(&philo.forks[i], NULL);
		printf("thread %d pid %d \n", pthread_mutex_init(&philo.forks[i], NULL), getpid());		
	}
	printf("apres la création des mutex.\n");
}

void	init_thread(t_philo philo)
{
	int	i;

	philo.threads = malloc(sizeof(pthread_t) * philo.nb_philo);
	if (philo.threads == NULL)
		ft_error("REDle malloc des threads qui deconne");
	i = philo.nb_philo;
	printf("Avant la création des threads.\n");
	while (i--)
	{		
		pthread_create(&philo.threads[i], NULL, &gestphilo, (void *)&philo);
		pthread_join(philo.threads[i], NULL);		
	}
	printf("apres la création des threads.\n");
}
