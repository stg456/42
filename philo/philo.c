/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/15 15:39:26 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(void *arg)
{

	printf("Après la création du thread.\n");
	usleep(1000);
}

int	main(int argc, char **argv)
{
	t_arg		param;
	t_philo		philo;
	t_chrono	chrono;
	int			i;

	// philo = malloc(sizeof(*philo)* param.nb_philo);
	// if (philo == NULL)
	// 	exit(EXIT_FAILURE);

	init_arg(argc, argv, param);
	// if (param.nb_philo = 1)
	// {
	// 	philo_dead();
	// }
	init_fork(&philo, &param);
	init_guy(&philo, &param);


	return (0);
}
