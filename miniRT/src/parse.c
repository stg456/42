/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/10 15:54:38 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	amb(char *buf, t_data d)
{
	t_amb	A;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (buf[i] != '\n')
	{
		printf("dans A: %s\n", buf);
		if (buf[i] == ' ' || buf[i] == '\t')
			i++;
		else if (ft_strncmp(buf, "A", 1) == 0)
		{
			d.nbA += 1;
			i++;
		}
		// i++;
		printf("nb A: %d\n", d.nbA);
		if (buf[i] == ' ' || buf[i] == '\t')
			i++;
		printf("i: %d\n", i);
		if (buf[i] != ' ' && buf[i] != '\t')
			tmp[j++] = buf[i++];
		printf("tmp: %s\n", tmp);
		A.ratioA = ft_atof(tmp);
		printf("ratio: %lf\n", A.ratioA);
		// while (*buf == ' ' || *buf == '\t')
		// 	buf++;
		// while (*buf != ',')
		// 	A.rgb.r = ft_atoi(buf);
		// printf("%d\n", A.rgb.r);

		// buf++;
		// A.rgb.g = ft_atoi(buf);
		// buf++;
		// A.rgb.b = ft_atoi(buf);
		// i++;
	}
	return (d);
}

// void	cam(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strncmp(*buf, "C", 1) == 0)
// 			d.nbC += 1;
// 	}
// }

// void	lum(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strncmp(*buf, "L", 1) == 0)
// 			d.nbL += 1;
// 	}
// }

// void	sp(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strncmp(*buf, "sp", 2) == 0)
// 			d.nbsp += 1;
// 	}
// }

// void	pl(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strncmp(*buf, "pl", 2) == 0)
// 			d.nbpl += 1;
// 	}
// }

// void	cyl(char *buf, t_data d)
// {
// 	while (*buf)
// 	{
// 		if (ft_strncmp(*buf, "cy", 2) == 0)
// 			d.nbcy += 1;
// 	}
// }

