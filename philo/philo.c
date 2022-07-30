/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/30 18:10:14 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **argv, t_arg	param)
{
	param.nb_philo = ft_atoi(argv[1]);
	param.time_to_die = ft_atoi(argv[2]);
	param.time_to_eat = ft_atoi(argv[3]);
	param.time_to_sleep = ft_atoi(argv[4]);
}

void	*gestphilo(void *arg)
{

	printf("Après la création du thread.\n");
	usleep(1000);
}

int	main(int argc, char **argv)
{
	t_arg		param;
	pthread_t	philo;
	int			i;

	// philo = malloc(sizeof(*philo)* param.nb_philo);
	// if (philo == NULL)
	// 	return (-1);
	i = 0;
	if (argc != 5)
	{
		printf("REDError : Bad numbers of arguments.\n");
		return (0);
	}
	init_arg(argv, param);
	while (param.nb_philo != 0)
	{
		printf("Avant la création du thread.\n");
		pthread_create(&philo, NULL, &gestphilo, (void *)&philo);
		pthread_join(philo, NULL);
		// usleep(1000);
		i++;
		param.nb_philo--;
	}

	return (0);
}
