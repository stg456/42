/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:36 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/06 18:53:00 by stgerard         ###   ########.fr       */
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
	long long		runtime;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_t		verif;
	pthread_mutex_t	writing;
	int				dead;
	int				eat_mode;
}				t_philo;

// typedef struct s_philo
// {
// 	int				id;
// 	int				*lunch_time;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	writing;
// 	pthread_t		*threads;
// 	struct s_rules	rules;
// }				t_philo;

// main.c

int			main(int ac, char **av);

// init.c

int			init_all(int ac, char **av, t_philo *ph);

// manage.c

void		*gestphilo(void *ptr);

// utils.c

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

// time.c

long long	timestamp(void);
long long	diff_chrono(t_philo ph);
void		ft_wait(long long delay);

#endif