/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 18:15:32 by stgerard         ###   ########.fr       */
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

# define RESET "\e[0m"
# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

enum e_msg
{
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DIED
};

typedef struct s_rules
{
	size_t			nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	long long		runtime;
	size_t			alive;
	int				dead;
	int				eat_mode;
}				t_rules;

typedef struct s_philo
{
	size_t			id;
	int				*lunch_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	dead;
	pthread_t		*threads;
	pthread_t		police;
	struct s_rules	rules;
	struct timeval	t;
}				t_philo;

// philo.c

int			init_arg(int argc, char **argv, t_philo *philo);
int			init_mutex(t_philo *philo);
int			init_thread(t_philo *philo);
void		*gestphilo(void *ptr);
void		*check_end(void *ptr);
void		solitude(t_philo *philo, int id);
int			gestphilo_lunch(t_philo *philo, int *nb_lunch);
int			philo_dead(t_philo *philo, int id);

// philolife.c

void		eating(t_philo *philo, size_t id);
void		sleeping(t_philo *philo, size_t id);
void		ft_print(t_philo *philo, int msg, int id);
void		gest(t_philo *philo, int id);

// time

long long	timestamp(void);
long long	chrono(t_philo *philo);
void		ft_wait(long long delay);
void		closephilo(t_philo *philo);

// utils

int			ft_atoi(const char *str);
void		ft_error(char *str);
int			ft_isdigit(int c);
int			ft_isdigit_str(char *str);

#endif