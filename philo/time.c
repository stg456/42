/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:55:56 by stgerard          #+#    #+#             */
/*   Updated: 2022/08/29 16:56:01 by stgerard         ###   ########.fr       */
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