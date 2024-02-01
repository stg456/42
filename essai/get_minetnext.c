/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minetnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:51:45 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/25 13:36:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_minetnext(int *stack, int len)
{
	int	pos;
	int	min;
	int	next;

	min = -2147483647;
	pos = 0;
	while (stack[pos] <= 2147483647)
	{
		while (stack[pos] != min)
		{
			while (pos < len)
			{
				if (stack[pos] == min)
					return (pos);
				pos++;
			}
			min++;
		}
	}
	return (pos);
}

int	algo(int *stack, int len, int pos)
{
	int	min;
	int	i;
    int next;

    
    min = next;
	min = -2147483647;
    get_minetnext(*stack, len);

    next = &pos;
}
