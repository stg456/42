/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/29 14:47:25 by stgerard         ###   ########.fr       */
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
	philo->id = 0;
	printf("debut routine.\n");
	// timestamp
	while (philo->id++ <= philo->rules->nb_philo && philo->rules->nb_eat)
	{
		while (i % 2 <= rules.nb_philo && rules.nb_eat > 0)
		{
			ft_print(philo, "FORK"); // has taken a fork pb
			eating(rules, philo);
			i++;
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
	init_arg(argc, argv, &rules);
	philo->rules = &rules;
	if (init_mutex(philo) || init_thread(philo))
		return (1);
	init_mutex(philo);
	init_thread(philo);
	closephilo(philo);

	return (0);
}
