/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:16:58 by stgerard          #+#    #+#             */
/*   Updated: 2022/11/08 13:29:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count(char c)
{
	int res = 0;

	if (c >= 'A' && c <= 'Z')
		res = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		res = c - 'a' + 1;
	else
		res = 1;
	return (res);
}

int main(int ac, char **av)
{
	int i = 0;
	int res = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			res = count(av[1][i]);
			while (res--)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}