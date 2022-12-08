/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/07 11:09:27 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*ph;

	ph = malloc(sizeof(t_philo));
	memset(ph, 0, sizeof(t_philo));
	if (!ph)
	{
		printf("Malloc error\n");
		return (1);
	}
	if (init_all(ac, av, ph) == 1)
	{
		printf("init error\n");
		return (1);
	}

	// 1 thread pour verif les timestamp

	return (0);
}
