/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:28 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/07 11:09:27 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(int ac, char **av, t_philo *ph)
{
	size_t	i;

	i = 0;
	if (ft_isdigit_str(av[1]) || ft_isdigit_str(av[2])
		|| ft_isdigit_str(av[3]) || ft_isdigit_str(av[4]))
		return (1);
	if (ph->nb_philo < 0 || ph->time_die < 0 || ph->time_eat < 0
		|| ph->time_sleep < 0)
		return (1);
	if (ac == 6 && (ft_isdigit_str(av[5]) || ph->nb_eat < 0))
		return (1);
	return (0);
}

static int	init_arg(int ac, char **av, t_philo *ph)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error : Bad numbers of arguments.");
		return (1);
	}
	ph->nb_philo = ft_atoi(av[1]);
	ph->time_die = ft_atoi(av[2]);
	ph->time_eat = ft_atoi(av[3]);
	ph->time_sleep = ft_atoi(av[4]);
	ph->eat_mode = 0;
	if (ac == 6)
	{
		ph->nb_eat = ft_atoi(av[5]);
		ph->eat_mode = 1;
	}
	return (0);
}

static int	init_mutex(t_philo *ph)
{
	size_t	i;

	i = 0;
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->nb_philo);
	pthread_mutex_init(&ph->writing, NULL);
	if (ph->forks == NULL)
	{
		printf("Mutex malloc error\n");
		return (1);
	}
	while ((int)i < ph->nb_philo)
	{
		pthread_mutex_init(&ph->forks[i], NULL);
		++i;
	}
	return (0);
}

static int	init_thread(t_philo *ph)
{
	size_t		i;
	pthread_t	verif;

	i = 0;
	ph->threads = malloc(sizeof(pthread_t) * ph->nb_philo);
	pthread_create(&ph->verif[i], 0, &verif_death, ph);
	if (ph->threads == NULL)
	{
		printf("Pthread malloc error\n");
		return (1);
	}
	while ((int)i < ph->nb_philo)
	{
		pthread_create(&ph->threads[i], 0, &gestphilo, ph);

		++i;
	}
	i = 0;
	while ((int)i < ph->nb_philo)
	{
		pthread_join(ph->threads[i], NULL);
		i++;
		if (ph->dead == 1)
			return (1);
	}
	return (0);
}

int	init_all(int ac, char **av, t_philo *ph)
{
	if (init_arg(ac, **av, ph) == 1)
	{
		printf("a \n");
		return (1);
	}
	if (check_arg(ac, **av, ph) == 1)
	{
		printf("b \n");
		return (1);
	}
	if (init_mutex(ph) == 1)
	{
		printf("c \n");
		return (1);
	}
	if (init_threads(ph) == 1)
	{
		printf("d \n");
		return (1);
	}
	return (0);
}
