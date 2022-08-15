/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/15 13:10:27 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(int argc, char **argv, t_arg	param)
{
	if (argc < 5 || argc > 6)
	{
		printf("REDError : Bad numbers of arguments.\n");
		return (-1);
	}
	param.nb_philo = ft_atoi(argv[1]);
	param.time_die = ft_atoi(argv[2]);
	param.time_eat = ft_atoi(argv[3]);
	param.time_sleep = ft_atoi(argv[4]);
	if (argc == 6) 
		param.nb_eat = ft_atoi(argv[5]);
	else
		param.nb_eat = -1;
}

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
	// 	return (-1);

	init_arg(argc, argv, param);
	// if (param.nb_philo = 1)
	// {
	// 	philo_dead();
	// }
	init_mutex(&philo, &param);


	i = 0;
	while (param.nb_philo != 0)
	{
		printf("Avant la création du thread.\n");
		pthread_create(&philo, NULL, &gestphilo, (void *)&philo);
		// pthread_join(&philo, NULL);
		// usleep(1000);
		i++;
		param.nb_philo--;
	}

	return (0);
}
