/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:05:54 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/26 09:21:39 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_struct *list)
{
	int	i;
	int	tmp;

	i = list->len_a - 1;
	if (list->len_a > 1)
	{
		tmp = list->stack_a[list->len_a - 1];
		while (i >= 0)
		{
			list->stack_a[i] = list->stack_a[i - 1];
			i--;
		}
		list->stack_a[0] = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_struct *list)
{
	int	i;
	int	tmp;

	i = list->len_b - 1;
	if (list->len_b > 1)
	{
		tmp = list->stack_b[list->len_b - 1];
		while (i >= 0)
		{
			list->stack_b[i] = list->stack_b[i - 1];
			i--;
		}
		list->stack_b[0] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_struct *list)
{
	int	i;
	int	tmp;

	i = list->len_a;
	if (list->len_a > 1)
	{
		tmp = list->stack_a[list->len_a - 1];
		while (--i >= 0)
			list->stack_a[i] = list->stack_a[i - 1];
		list->stack_a[0] = tmp;
	}
	i = list->len_b;
	if (list->len_b > 1)
	{
		tmp = list->stack_b[list->len_b - 1];
		while (--i >= 0)
			list->stack_b[i] = list->stack_b[i - 1];
		list->stack_b[0] = tmp;
	}
	write(1, "rrr\n", 4);
}
