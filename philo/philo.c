/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/01 17:51:22 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		ft_print(philo, THINK, id);
		if (diff_chrono(*philo) - philo->lunch_time[id - 1] > philo->rules.time_die)
		{
			pthread_mutex_lock(&philo->writing);
			ft_print(philo, DIED, id);
			philo->rules.dead = 1;
			pthread_mutex_unlock(&philo->dead);
		}
	}
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
	//closephilo(philo);
	return (0);
}
