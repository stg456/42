/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:59:55 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/27 12:06:44 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'C' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'F'))
			perror("\x1B[31mError : unknown characters in map file.");
			exit(EXIT_FAILURE);
		i++;
	}
}

void	wall_check(t_env *e)
{
	char	*str;
	int		i;

	i = 0;
	str[i] = e->map;
	while (str[i] != '\0')
	{
		while (str[i] != '\n')
		{
			if (str[i--] != '1' || str[i++] != '1')
			{
				perror("\x1B[31mInvalid map\n");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		i++;
		if (str[i] != '1')
			{
				perror("\x1B[31mInvalid map\n");
				exit(EXIT_FAILURE);
			}
		i++;
	}
	while (str[i--] != '/n')
	{
		if (str[i] != '1')
		{
			perror("\x1B[31mInvalid map\n");
			exit(EXIT_FAILURE);
		}
	}
}

int	min_check(t_env *e)
{
	int		i;
	char	*str;
	int		C;
	int		E;
	int		P;
	
	i = 0;

	C = 0;
	E = 0;
	P = 0;
	str[i] = e->map;
	while (str[i] != '\0')
	{
		if (str[i] = 'C')
			C++;
		else if (str[i] = 'E')
			E++;
		else if (str[i] = 'P')
			P++;
		i++;
	}
	if (C !+ 1 || E != 1 || P != 1)
	{
		perror("\x1B[31mInvalid map\n");
		exit(EXIT_FAILURE);
	}
	return (0);

}

int	check(t_env *e)
{
	char_check(e);
	wall_check(e);
	min_check(e);

	return (0);
}