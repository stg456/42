/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/07 14:35:46 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_end(void *ptr)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ptr;
	while (!philo->rules.dead)
	{
		if (diff_chrono(*philo) - philo->lunch_time[i] > philo->rules.time_die)
		{
			philo->rules.dead = 1;
			printf("\x1B[31m%lld philo %d died\n\x1B[0m", diff_chrono(*philo), i + 1);
			pthread_mutex_unlock(&philo->dead);
		}
		if (i == philo->rules.nb_philo - 1)
			i = -1;
		i++;
	}
	return (NULL);
}


void	*gestphilo(void *ptr)
{
	t_philo	*philo;
	int		id;
	int		nb_lunch;

	philo = ptr;
	id = philo->id++;
	philo->lunch_time[id - 1] = diff_chrono(*philo);
	nb_lunch = philo->rules.nb_eat;
	while (philo->rules.dead == 0)
	{
		if (philo->rules.eat_mode == 1)
		{
			nb_lunch--;
			if (nb_lunch <= 0)
				break ;
		}
		eating(philo, id);
		sleeping(philo, id);
		pthread_mutex_lock(&philo->writing);
		printf("\x1B[36m%lld philo %i is thinking\n\x1B[0m", diff_chrono(*philo), id);
		pthread_mutex_unlock(&philo->writing);
//		if (diff_chrono(*philo) - philo->lunch_time[id - 1] > philo->rules.time_die)
//		{
//			philo->rules.dead = 1;
//			printf("\x1B[31m%lld philo %d died\n\x1B[0m", diff_chrono(*philo), id);
//			break ;
//		}
	}
	printf("toto\n");
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
