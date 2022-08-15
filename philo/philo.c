/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/15 16:46:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(void *arg)
{

	printf("Après la création du thread.\n");
	// usleep(1000);
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
	init_mutex(&philo, &param);
	init_thread(&philo, &param);


	return (0);
}
