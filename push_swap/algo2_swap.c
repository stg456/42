/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:53:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/26 10:38:24 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alg3(t_struct *list)
{
	if (list->stack_a[1] < list->stack_a[0])
		ft_sa(list);
	if (!check_sort(list))
		ft_rra(list);
	if (list->stack_a[1] < list->stack_a[0])
		ft_sa(list);
}

static void	alg4(t_struct *list)
{
	int	i;
	int	min;

	i = 0;
	min = list->stack_a[get_min(list->stack_a, list->len_a)];
	while (i < list->len_a)
	{
		if (list->stack_a[0] == min)
			ft_pb(list);
		else if (list->stack_a[list->len_a - 1] == min)
		{
			ft_rra(list);
			ft_pb(list);
		}
		else
			ft_ra(list);
		i++;
	}
	alg3(list);
	ft_pa(list);
}

static void	alg5_get_min_max(t_struct *list, int min, int max)
{
	int	i;

	i = 0;
	while (i < list->len_a)
	{
		if (list->stack_a[0] == min || list->stack_a[0] == max)
			ft_pb(list);
		else if (list->stack_a[list->len_a - 1] == min
			|| list->stack_a[list->len_a - 1] == max)
		{
			ft_rra(list);
			ft_pb(list);
		}
		else
			ft_ra(list);
		i++;
	}
}

static void	alg5(t_struct *list)
{
	int	n;
	int	min;
	int	max;

	n = list->len_a - 3;
	min = list->stack_a[get_min(list->stack_a, list->len_a)];
	max = list->stack_a[get_max(list->stack_a, list->len_a)];
	alg5_get_min_max(list, min, max);
	alg3(list);
	while (n)
	{
		ft_pa(list);
		if (list->stack_a[0] == max)
			ft_ra(list);
		ft_pa(list);
		n--;
	}
}

void	small_algo(t_struct *list)
{
	if (list->len_a < 4)
		alg3(list);
	else if (list->len_a < 5)
		alg4(list);
	else
		alg5(list);
}
