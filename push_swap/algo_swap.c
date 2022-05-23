/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:41:22 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/26 10:38:24 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_index(t_struct *list)
{
	int	i;
	int	*stmp;
	int	tmp;

	i = 0;
	stmp = malloc(sizeof(int) * list->len_a);
	if (!stmp)
	{
		free(stmp);
		push_swap_error(list);
	}
	tmp = get_min(list->stack_a, list->len_a);
	stmp[tmp] = 0;
	while (++i < list->len_a)
	{
		tmp = get_next_min(list->stack_a, list->len_a, list->stack_a[tmp]);
		stmp[tmp] = i;
	}
	while (i >= 0)
	{
		list->stack_a[i] = stmp[i];
		i--;
	}
	free(stmp);
}

int	check_sort(t_struct *list)
{
	int	i;

	i = 0;
	while (i < list->len_a)
	{
		if (list->stack_a[i] > list->stack_a[i + 1] && i < list->len_a - 1)
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort(t_struct *list)
{
	int	i;
	int	j;
	int	bits;

	i = 0;
	bits = ft_intlen(ft_dectobin(list->len_a - 1));
	while (i < bits)
	{
		j = 0;
		while (j++ < list->max_length)
		{
			if (((list->stack_a[0] >> i) & 1) == 1)
				ft_ra(list);
			else
				ft_pb(list);
		}
		while (list->len_b != 0)
			ft_pa(list);
		i++;
	}
}

int	push_swap_algo(t_struct *list)
{
	if (check_sort(list))
		return (1);
	if (list->len_a <= 5)
		small_algo(list);
	if (list->len_a > 5)
	{
		stack_to_index(list);
		radix_sort(list);
	}
	return (0);
}
