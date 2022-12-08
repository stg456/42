/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaur <albaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:55:56 by stgerard          #+#    #+#             */
/*   Updated: 2022/12/08 14:10:27 by albaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(long long delay)
{
	long long	t;
	long long	start;

	t = timestamp();
	start = t;
	while (t < start + delay)
		t = timestamp();
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

long long	diff_chrono(t_philo *philo)
{
	long long		ms;

	gettimeofday(&philo->t, NULL);
	ms = (philo->t.tv_sec * 1000 + philo->t.tv_usec / 1000);
	return ((ms - philo->rules.runtime));
}
