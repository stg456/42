/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:55:38 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/05 10:01:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	free_strs(char **tmp, char **tmp_pos, char **tmp_axe,
	char **tmpcolor)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
			free (tmp[i++]);
	}
	i = 0;
	if (tmp_pos)
	{
		while (tmp_pos[i])
			free (tmp_pos[i++]);
	}
	i = 0;
	if (tmp_axe)
	{
		while (tmp_axe[i])
			free (tmp_axe[i++]);
	}
	i = 0;
	if (tmpcolor)
	{
		while (tmpcolor[i])
			free(tmpcolor[i++]);
	}
}

void	free_all(char **tmp, char **tmp_pos, char **tmp_axe, char **tmpcolor)
{
	free_strs(tmp, tmp_pos, tmp_axe, tmpcolor);
	if (tmp_pos)
	{
		free(tmp_pos);
		tmp_pos = NULL;
	}
	if (tmp_axe)
	{
		free(tmp_axe);
		tmp_axe = NULL;
	}
	if (tmpcolor)
	{
		free(tmpcolor);
		tmpcolor = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

int	close_hook(t_data *d, int code)
{
	mlx_terminate(d->env.mlx);
	if (code == 0)
		exit(EXIT_SUCCESS);
	else
		exit (EXIT_FAILURE);
}
