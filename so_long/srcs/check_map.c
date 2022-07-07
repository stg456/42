/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:59:55 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/07 19:35:03 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
					|| e->map[i][j] == 'P' || e->map[i][j] == 'F'
					|| e->map[i][j] == 'X'))
				ft_error("\x1B[31mError: unknown characters in map file.");
			++j;
		}
		++i;
	}
}

static void	wall_check2(t_env *e)
{
	int	i;

	i = 0;
	while (e->map[i])
	{
		if (e->map[i][0] != '1' && e->map[i][ft_strlen(e->map[i])] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	e->size_y = i;
	i = 0;
	while (e->map[e->size_y - 1][i])
	{
		if (e->map[e->size_y - 1][i] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
}

static void	wall_check(t_env *e)
{
	size_t	i;

	i = 0;
	e->size_x = 0;
	e->size_y = 0;
	while (e->map[0][i])
	{
		if (e->map[0][i] != '1')
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	e->size_x = i;
	i = 0;
	while (e->map[i])
	{
		if (ft_strlen(e->map[i]) != (size_t)e->size_x)
			ft_error("\x1B[31mInvalid map\n");
		++i;
	}
	wall_check2(e);
}

static void	min_check(t_env *e)
{
	t_check	v;

	v.i = 0;
	v.j = 0;
	v.n_c = 0;
	v.n_e = 0;
	v.n_p = 0;
	while (e->map[v.i])
	{
		v.j = 0;
		while (e->map[v.i][v.j])
		{
			if (e->map[v.i][v.j] == 'C')
				v.n_c++;
			else if (e->map[v.i][v.j] == 'E')
				v.n_e++;
			else if (e->map[v.i][v.j] == 'P')
				v.n_p++;
			++v.j;
		}
		++v.i;
	}
	if (v.n_c < 1 || v.n_e < 1 || v.n_p != 1)
		ft_error("\x1B[31mInvalid map\n");
	e->collectible = v.n_c;
}

int	check(t_env *e)
{
	char_check(e);
	wall_check(e);
	min_check(e);
	return (0);
}
