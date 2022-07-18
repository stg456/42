/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:48 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/18 16:09:45 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	init(char **argv, t_arg	param)
{
	param.nb_philo = ft_atoi(argv[1]);
	param.time_to_die = ft_atoi(argv[2]);
	param.time_to_eat = ft_atoi(argv[3]);
	param.time_to_sleep = ft_atoi(argv[4]);
}

int	main(char **argv)
{
	t_arg	param;
	int		i;

	i = 0;
	init_arg(argv, param);
	while (param.nb_philo != 0)
	{
		pthread_create();
	}

}
