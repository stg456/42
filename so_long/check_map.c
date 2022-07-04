/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:59:55 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/04 12:06:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_check(t_env *e)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (!(e->map[i][j] == '0' || e->map[i][j] == '1' 
					|| e->map[i][j] == 'C' || e->map[i][j] == 'E'
					|| e->map[i][j] == 'P' || e->map[i][j] == 'F'))
				ft_error("\x1B[31mError: unknown characters in map file.");
			++j;
		}
		++i;
	}
}

static void	wall_check(t_env *e)
{
	size_t	i;

	i = 0;
	e->size_x = 0;
	e->size_y = 0;
	while (e->map[0][i]) // check 1ere ligne uniquement des 1
	{
		if (e->map[0][i] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	e->size_x = i;
	i = 0;
	while (e->map[i]) // check que toutes les lignes soient de la meme long
	{
		if (ft_strlen(e->map[i]) != (size_t)e->size_x)
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	i = 0;
	while (e->map[i])  // check 1ere colonne et derniere colonne = 1
	{
		if (e->map[i][0] != '1' && e->map[i][ft_strlen(e->map[i])] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	e->size_y = i;
	i = 0;
	while (e->map[e->size_y - 1][i]) // check derniere ligne uniquement des 1
	{
		if (e->map[e->size_y - 1][i] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
}

static void	min_check(t_env *e)
{
	size_t	i;
	size_t	j;
	int		n_c;
	int		n_e;
	int		n_p;

	i = 0;
	j = 0;
	n_c = 0;
	n_e = 0;
	n_p = 0;
	while (e->map[i])
	{
		j = 0;
		while(e->map[i][j])
		{
			if (e->map[i][j] == 'C')
				n_c++;
			else if (e->map[i][j] == 'E')
				n_e++;
			else if (e->map[i][j] == 'P')
				n_p++;
			++j;
		}
		++i;
	}
	if (n_c != 1 || n_e != 1 || n_p != 1)
		ft_error("\x1B[31mInvalid map\n");
}

int	check(t_env *e)
{
	char_check(e);
	wall_check(e);
	min_check(e);
	return (0);
}
