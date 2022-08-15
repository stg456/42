/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/15 11:18:21 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#define RESET "\e[0m"
#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_arg
{
	int	nb_philo;
	int	time_die;
	int time_eat;
	int time_sleep;
	int	nb_eat;
}				t_arg;

// typedef struct s_state
// {
// 	int	eat;
// 	int	sleep;
// 	int	think;
// 	int dead;
// }				t_state;

// typedef struct s_fork
// {
// 	int	left;
// 	int	right;
// }				t_fork;

typedef struct s_philo
{
	int			id;
	int			nb_time;
	int 		time_die;
	// t_fork	fork;
	pthread_t	thread;
}				t_philo;

// fct

void	init_arg(int argc, char **argv, t_arg	param);
void	*gestphilo(void *arg);

// utils

int	ft_atoi(const char *str);

#endif