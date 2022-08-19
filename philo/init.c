/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:28 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/19 12:39:51 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(int argc, char **argv, t_arg	param)
{
	t_arg		param;
	
	if (argc < 5 || argc > 6)
	{
		printf("REDError : Bad numbers of arguments.\n");
		return (-1);
	}
	param.nb_philo = ft_atoi(argv[1]);
	param.time_die = ft_atoi(argv[2]);
	param.time_eat = ft_atoi(argv[3]);
	param.time_sleep = ft_atoi(argv[4]);
	if (argc == 6) 
		param.nb_eat = ft_atoi(argv[5]);
}

void	init_mutex(t_philo philo, t_arg param)
{
	int	i;

	philo.forks = malloc(sizeof(pthread_mutex_t) * param.nb_philo);
	if (philo.forks == NULL)
		ft_error("REDle malloc des fork qui deconne");
	i = param.nb_philo;
	printf("Avant la création des mutex.\n");
	while (i--)
	{
		pthread_mutex_init(&philo.forks, NULL);
		printf("apres la création des mutex.\n");
	}
}

void	init_thread(t_philo philo, t_arg param)
{
	int	i;

	philo.threads = malloc(sizeof(pthread_t) * param.nb_philo);
	if (philo.threads == NULL)
		ft_error("REDle malloc des threads qui deconne");
	i = param.nb_philo;
	printf("Avant la création des thread.\n");
	while (i--)
	{		
		pthread_create(&philo.threads, NULL, &gestphilo, (void *)&philo);
		printf("apres la création des thread.\n");
	}
}
