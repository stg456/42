/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:21:32 by stgerard          #+#    #+#             */
/*   Updated: 2022/06/16 16:21:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string msg to the standard output followed by an exit of the
** program with a custom return value (defined by ret).
*/

void	ft_puterror(char *msg, int ret)
{
	ft_putendl(msg);
	exit(ret);
}