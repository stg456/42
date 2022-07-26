/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/26 16:15:46 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#define NRM  \x1B[0m
#define RED  \x1B[31m
#define GRN  \x1B[32m
#define YEL  \x1B[33m
#define BLU  \x1B[34m
#define MAG  \x1B[35m
#define CYN  \x1B[36m
#define WHT  \x1B[37m

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

void	init_arg(char **argv, t_arg	param);
void	*gestphilo(void *arg);

// utils

int	ft_atoi(const char *str);

#endif