/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/02 16:27:35 by stgerard         ###   ########.fr       */
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
		// printf("philoLunch %lld\n", diff_chrono(*philo) - philo->lunch_time[id - 1]);
		if (diff_chrono(*philo) - philo->lunch_time[id - 1] > philo->rules.time_die)
		{
			// printf("philoLunch\n");
			// pthread_mutex_lock(&philo->writing);
			// ft_print(philo, DIED, id);
			philo->rules.dead = 1;
			ft_print(philo, DIED, id);
			pthread_mutex_lock(&philo->dead); // pb boucle infini
			return (NULL);
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
	// pthread_mutex_lock(&philo->dead);
	// pthread_mutex_unlock(&philo->writing);
	// pthread_mutex_unlock(&philo->dead);
	closephilo(philo);
	return (0);
}
