/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 15:08:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*gestphilo(void *ptr)
{
	t_philo	*philo;
	t_rules	rules;
	int		i;

	philo = (t_philo *)ptr;
	rules = *philo->rules;
	i = 1;
	philo->id = 1;
	printf("debut routine.\n");
	// timestamp
	// printf("%d \n", philo->rules->nb_philo);
	printf("%d \n", rules.nb_philo);
	// printf("%d \n", philo->id);
	while (philo->id++ <= philo->rules->nb_philo && philo->rules->nb_eat)
	{
		printf("1 \n");
		while (philo->id % 2 <= rules.nb_philo && rules.nb_eat > 0)
		{
			printf("2 \n");
			ft_print(philo, "FORK"); // has taken a fork pb
			printf("3 \n");
			eating(rules, philo);
			printf("4 \n");
			philo->id++;
		}
		// philo->rules->nb_eat--;
	}
	printf("fin routine.\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_rules		rules;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		printf("Malloc error\n");
		return (1);
	}
	init_arg(argc, argv, rules);
	philo->rules = &rules;
	if (init_mutex(philo) || init_thread(philo))
		return (1);
	init_mutex(philo);
	init_thread(philo);
	closephilo(philo);

	return (0);
}
