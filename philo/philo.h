/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/25 14:18:17 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <time.h>

# define RESET "\e[0m"
# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_rules
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				nb_of_eat;
}				t_rules;

typedef struct s_philo
{
	int				id;
	int				time_before_die;
	int				l_fork;
	int				r_fork;
	int				ate;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*writing;
	struct timeval	start;
	struct timeval	end;
	struct s_rules	*rules;

	// struct s_philo	*next_philo;
}				t_philo;

// fct

void	init_arg(int argc, char **argv);
void	init_mutex(t_philo *philo);
void	init_thread(t_philo *philo);
void	*gestphilo(t_philo *philo);
void	*closephilo(t_philo *philo);

// utils

int		ft_atoi(const char *str);
void	ft_error(char *str);

#endif