/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:55:56 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/21 11:00:16 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	diff_chrono(t_philo philo, t_chrono chrono)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
    // loopFunc(NUM);
    gettimeofday(&end, NULL);

}

// float time_diff(struct timeval *start, struct timeval *end)
// {
//     return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
// }

// long	ft_time(void)
// {
// 	struct timeval	tv;
// 	long			res;

// 	gettimeofday(&tv, NULL);
// 	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
// 	return (res);
// }