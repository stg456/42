/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/12 17:22:18 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(t_philo *philo)
{
	int	i;

	i = 0;
	printf("debut routine.\n");
	while (philo->id <= philo->rul->nb_philo)
	{
		// take forks
		// eat
		// sleep
		// think
		// dead
	}

	printf("fin routine.\n");
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_rules		*rules;
	

	init_arg(argc, argv, rules);

	init_mutex(philo);
	init_thread(philo);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
