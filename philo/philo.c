/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/29 12:13:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(t_philo philo)
{
	printf("debut routine.\n");
	
	// usleep(1000);
	printf("fin routine.\n");
}

void	ft_error(char *str)
{
	printf(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_chrono	chrono;
	t_arg		param;
	int			i;

	// philo = malloc(sizeof(t_philo) * param.nb_philo);
	// if (philo == NULL)
	// 	exit(EXIT_FAILURE);

	init_arg(argc, argv, param);
	// if (param.nb_philo = 1)
	// {
	// 	philo_dead();
	// }
	init_mutex(philo, param);
	init_thread(philo, param);
	gestphilo(philo);
	closephilo(philo);

	return (0);
}
