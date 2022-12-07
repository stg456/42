/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:57:24 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/08 10:58:57 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_struct *list)
{
	int	i;
	int	tmp;

	i = 0;
	if (list->len_a > 1)
	{
		tmp = list->stack_a[i];
		while (i < list->len_a - 1)
		{
			list->stack_a[i] = list->stack_a[i + 1];
			i++;
		}
		list->stack_a[list->len_a - 1] = tmp;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_struct *list)
{
	int	i;
	int	tmp;

	i = 0;
	if (list->len_b > 1)
	{
		tmp = list->stack_b[i];
		while (i < list->len_b - 1)
		{
			list->stack_b[i] = list->stack_b[i + 1];
			i++;
		}
		list->stack_b[list->len_b - 1] = tmp;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_struct *list)
{
	int	i;
	int	tmp;

	i = -1;
	if (list->len_a > 1)
	{
		tmp = list->stack_a[i];
		while (++i < list->len_a)
			list->stack_a[i] = list->stack_a[i + 1];
		list->stack_a[list->len_a - 1] = tmp;
	}
	i = -1;
	if (list->len_b > 1)
	{
		tmp = list->stack_b[i];
		while (++i < list->len_b)
			list->stack_b[i] = list->stack_b[i + 1];
		list->stack_b[list->len_b - 1] = tmp;
	}
	write(1, "rr\n", 3);
}
