/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 12:04:16 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo, int id)
{
	if (philo->rules.dead == 1)
		return (1);
	if (diff_chrono(*philo) - philo->lunch_time[id - 1] > philo->rules.time_die)
	{
		pthread_mutex_lock(&philo->writing);
		philo->rules.dead = 1;
		printf("\x1B[31m%lld philo %i %s", diff_chrono(*philo), id, "died\n\x1B[0m");
		pthread_mutex_unlock(&philo->dead);
		return (1);
	}
	return (0);
}

void	closephilo(t_philo *philo)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < philo->rules.nb_philo)
	{
		pthread_join(philo->threads[j], NULL);
		j++;
	}
	i = 0;
	while (i < philo->rules.nb_philo)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->writing);
	pthread_mutex_destroy(&philo->dead);
	free(philo->forks);
	free(philo->threads);
	free(philo->lunch_time);
	free(philo);
}

void	solitude(t_philo *philo)
{
	ft_print(philo, FORK, 1);
	ft_wait(philo->rules.time_die);
	philo->rules.dead = 1;
	ft_print(philo, DIED, 1);
	pthread_mutex_unlock(&philo->dead);
}

void	*gestphilo(void *ptr)
{
	t_philo	*philo;
	int		id;
	int		nb_lunch;

	philo = ptr;
	id = philo->id++;
	nb_lunch = philo->rules.nb_eat;
	while (philo->rules.dead == 0)
	{
		if (!philo_dead(philo, id))
			eating(philo, id);
		if (!philo_dead(philo, id))
			sleeping(philo, id);
		if (!philo_dead(philo, id))
			ft_print(philo, THINK, id);
		if (gestphilo_lunch(philo, &nb_lunch) == 1)
			break ;
	}
	philo->rules.alive--;
	if (philo->rules.alive == 0)
		pthread_mutex_unlock(&philo->dead);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	if (!philo)
	{
		printf("Malloc error\n");
		return (1);
	}
	if (init_arg(argc, argv, philo) || init_mutex(philo) || init_thread(philo))
		return (1);
	pthread_mutex_lock(&philo->dead);
	pthread_mutex_unlock(&philo->dead);
	closephilo(philo);
	return (0);
}
