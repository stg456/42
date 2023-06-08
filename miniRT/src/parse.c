/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/08 18:30:14 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	amb(char *buf, t_data d)
{
	t_amb	A;
	char	*tmp;
	int		i;

	i = 0;
	if (*buf != '\n')
	{
		printf("dans A; %s\n", buf);
		
		if (ft_strncmp(buf, "A", 1) == 0)
			d.nbA += 1;
		
		while (*buf == ' ' || *buf == '\t')
			buf++;
		A.ratioA = ft_atof(buf);
		printf("%lf\n", A.ratioA);
		while (*buf == ' ' || *buf == '\t')
			buf++;
		A.rgb.r = ft_atoi(buf);
		printf("%d\n", A.rgb.r);
		buf++;
		A.rgb.g = ft_atoi(buf);
		buf++;
		A.rgb.b = ft_atoi(buf);
	}
	return (d);
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

