/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:01:25 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/20 11:52:11 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_struct *list)
{
	int	tmp;

	if (list->len_a > 1)
	{
		tmp = list->stack_a[1];
		list->stack_a[1] = list->stack_a[0];
		list->stack_a[0] = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_struct *list)
{
	int	tmp;

	if (list->len_b > 1)
	{
		tmp = list->stack_b[1];
		list->stack_b[1] = list->stack_b[0];
		list->stack_b[0] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_struct *list)
{
	int	tmp1;
	int	tmp2;

	if (list->len_a > 1)
	{
		tmp1 = list->stack_a[1];
		list->stack_a[1] = list->stack_a[0];
		list->stack_a[0] = tmp1;
		write(1, "sa\n", 3);
	}
	if (list->len_b > 1)
	{
		tmp2 = list->stack_b[1];
		list->stack_b[1] = list->stack_b[0];
		list->stack_b[0] = tmp2;
		write(1, "sb\n", 3);
	}
	write(1, "ss\n", 3);
}

void	ft_pa(t_struct *list)
{
	int	tmp;
	int	i;

	i = 0;
	if (list->len_b > 0)
	{
		tmp = list->stack_a[0];
		list->stack_a[0] = list->stack_b[0];
		while (i < list->len_b - 1)
		{
			list->stack_b[i] = list->stack_b[i + 1];
			i++;
		}
		list->stack_b[list->len_b - 1] = 0;
		list->len_a++;
		i = list->len_a - 1;
		while (i > 0)
		{
			list->stack_a[i] = list->stack_a[i - 1];
			i--;
		}
		list->stack_a[1] = tmp;
		list->len_b--;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_struct *list)
{
	int	tmp;
	int	i;

	i = 0;
	if (list->len_a > 0)
	{
		tmp = list->stack_b[0];
		list->stack_b[0] = list->stack_a[0];
		while (i < list->len_a - 1)
		{
			list->stack_a[i] = list->stack_a[i + 1];
			i++;
		}
		list->stack_a[list->len_a - 1] = 0;
		list->len_b++;
		i = list->len_b - 1;
		while (i > 0)
		{
			list->stack_b[i] = list->stack_b[i - 1];
			i--;
		}
		list->stack_b[1] = tmp;
		list->len_a--;
		write(1, "pb\n", 3);
	}
}
