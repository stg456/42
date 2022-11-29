/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:28 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 12:26:02 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(int argc, char **argv, t_rules *rules)
{
	if (argc < 5 || argc > 6)
		ft_error("REDError : Bad numbers of arguments.\n");
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);  
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->nb_eat = ft_atoi(argv[5]);
	rules->runtime = timestamp();
}

int	init_mutex(t_philo *philo)
{
	int	i;

	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->rules->nb_philo);
	if (philo->forks == NULL)
	{
		printf("Mutex malloc error\n");
		return (1);
	}
	i = philo->rules->nb_philo;
	// printf("Avant la création des mutex.\n");
	while (i-- > 0)
	{
		pthread_mutex_init(&(philo->forks)[i], NULL);
	}
	// printf("apres la création des mutex pour les forks.\n");
	return (0);
}

int	init_thread(t_philo *philo)
{
	int	i;

	philo->threads = malloc(sizeof(pthread_t) * philo->rules->nb_philo);
	if (philo->threads == NULL)
	{
		printf("Pthread malloc error\n");
		return (1);
	}
	i = philo->rules->nb_philo;
	// printf("Avant la création des threads.\n");
	while (i-- > 0)
	{
		pthread_create(&(philo->threads)[i], NULL, &gestphilo, &philo);
		pthread_detach((philo->threads)[i]);
		if (i % 2 == 0)
			usleep(500);
		philo->id = i;
		ft_print(philo, "creation thread");
	}
	// printf("apres la création des threads.\n");
	return (0);
}
