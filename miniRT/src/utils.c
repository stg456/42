/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/03 16:39:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	pass(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i])
			i++;
	}
	return (' ');
}

bool	ft_isrgb(int color)
{
	if (color >= 0 && color <= 255)
		return (true);
	return (false);
}

bool	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str) && str[i] != '\n' && str[i] != 'r')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

float	sqr(float f)
{
	return (f * f);
}

void		shapes_addback(t_elem **lst, t_elem *new, int *qty)
{
	t_elem	*aux;

	aux = (*lst);
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	(*qty)++;
}

t_elem	*elem_init()
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		ft_error("Elem Data Struct Init Error\n");
	ft_bzero(elem, sizeof(t_elem));
	return(elem);
}

t_vec	get_coor(char **split)
{
	t_vec	coor;

	coor.x = ft_atof(split[0]);
	coor.y = ft_atof(split[1]);
	coor.z = ft_atof(split[2]);
	return (coor);
}
