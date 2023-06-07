/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/07 18:21:39 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	amb(char *buf, t_data d)
{
	t_amb	A;

	while (*buf != '\n') // pb: boucle infini !
	{
		printf("%s\n", buf);
		if (ft_strncmp(buf, "A", 1) == 0)
			d.nbA += 1;
		while (*buf == ' ' || *buf == '\t')
			buf++;
		A.ratioA = ft_atof(buf);
		while (*buf == ' ' || *buf == '\t')
			buf++;
		A.Ar = ft_atoi(buf);
		printf("%s\n", buf);
		buf++;
		A.Ag = ft_atoi(buf);
		buf++;
		A.Ab = ft_atoi(buf);
	}
}

// void	cam(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strcmp(*buf, "C") == 0)
// 			d.nbC += 1;
// 	}
// }

// void	lum(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strcmp(*buf, "L") == 0)
// 			d.nbL += 1;
// 	}
// }

// void	sp(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strcmp(*buf, "sp") == 0)
// 			d.nbsp += 1;
// 	}
// }

// void	pl(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strcmp(*buf, "pl") == 0)
// 			d.nbpl += 1;
// 	}
// }

// void	cyl(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strcmp(*buf, "cy") == 0)
// 			d.nbcy += 1;
// 	}
// }

