/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:33:43 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/08 13:04:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int i)
{
	// char c;
	char *str = "0123456789";
	
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	write(1, &str[i % 10], 1);
}

int main(void)
{
	int i = 1;
	// char c;

	while (i <= 100)
	{
		// c = i + '0';
		if (i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizbuzz", 8);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz", 4);
			// write(1, "\n", 1);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 4);
			// write(1, "\n", 1);
		}
		else
		{
			ft_putnbr(i);
			// write(1, &c, 1);
			// write(1, "\n", 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

// pqas encore bon