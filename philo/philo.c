/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 16:18:59 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("debut routine.\n");
	// timestamp
	// printf("%d \n", philo->rules->nb_philo);
	printf("%d \n", philo->rules.nb_philo);
	// printf("%d \n", philo->id);
	while (philo->id <= philo->rules.nb_philo && philo->rules.nb_eat)
	{
		printf("1 \n");
		while (philo->id % 2 <= philo->rules.nb_philo && philo->rules.nb_eat > 0)
		{
			printf("2 \n");
			ft_print(philo, "FORK"); // has taken a fork pb
			printf("3 \n");
			eating(philo);
			printf("4 \n");
		}
		// philo->rules->nb_eat--;
	}
	printf("fin routine.\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		printf("Malloc error\n");
		return (1);
	}
	init_arg(argc, argv, philo);
	if (init_mutex(philo) || init_thread(philo))
		return (1);
	closephilo(philo);
	return (0);
}
