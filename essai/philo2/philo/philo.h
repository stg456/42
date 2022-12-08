/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 14:23:41 by stgerard         ###   ########.fr       */
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

typedef struct s_philo
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				id;
	long long		runtime;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_t		verif;
	pthread_mutex_t	writing;
	int				dead;
	int				eat_mode;
}				t_philo;

// main.c

int			main(int ac, char **av);

// init.c

int			init_all(int ac, char **av, t_philo *ph);

// manage.c

void		*gestphilo(void *ptr);
void		*verif_death(void *ptr);

// action.c

void		eating(t_philo *ph);
void		sleeping(t_philo *ph);
void		thinking(t_philo *ph);
void		died(t_philo *ph);

// utils.c

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

// time.c

long long	timestamp(void);
long long	chrono(t_philo ph);
void		ft_wait(long long delay);

#endif