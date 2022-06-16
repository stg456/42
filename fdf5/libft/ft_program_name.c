/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:19:10 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 16:19:33 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gets the name of the program (argv[0]).
*/

char	*ft_program_name(char const *argv0)
{
	char *name;

	name = (char *)argv0;
	while (*name && *name != '/')
		name += 1;
	if (!name)
		return ((char *)argv0);
	return (name + 1);
}