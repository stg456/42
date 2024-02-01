/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:47 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/06 15:22:03 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	shapes_addback(t_elem **lst, t_elem *new, int *qty)
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
	new->next = NULL;
	(*qty)++;
}

t_elem	*elem_init(void)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		ft_error("Error\nElem Data Struct Init Error\n");
	ft_bzero(elem, sizeof(t_elem));
	return (elem);
}

t_vec	get_coor(char **split)
{
	t_vec	coor;

	if (split_count(split) != 3)
		ft_error("Error\nInvalid coordinates\n");
	coor.x = ft_atof(split[0]);
	coor.y = ft_atof(split[1]);
	coor.z = ft_atof(split[2]);
	return (coor);
}
