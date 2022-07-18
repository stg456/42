/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/18 16:14:00 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


typedef struct s_state
{
	int	eat;
	int	sleep;
	int	think;
}				t_state;

typedef struct s_arg
{
	int	nb_philo;
	int	time_to_die;
	int time_to_eat;
	int time_to_sleep;
}				t_arg;

// fct

void	init(char **argv);

// utils

int	ft_atoi(const char *str);

#endif