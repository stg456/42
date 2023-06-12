/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:56 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/12 12:23:04 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	amb(char *buf, t_data d)
{
	t_amb	A;
	char	**tmp;
	int		i;
	int		j;

	i = 0; // index sur buf
	j = 0; // index sur tmp[j] 
	tmp = malloc(sizeof(char *) *	ft_strlen(buf) + 1);

	pass(buf);
	while (buf[i]) // boucle infini
	{
		printf("dans A: %s\n", buf);
		tmp = ft_split(buf, ' ');
		j++;
	}
	d.nbA += 1;
	printf("tmp: %s\n", tmp[0]);
	printf("nb A: %d\n", d.nbA);
	// printf("i: %d\n", i);
	// if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != 'A')
	// {
	// 	printf("a\n");
	// 	while (buf[i] != ' ' || buf[i] != '\t')
	// 	{
	// 		printf("b\n");
	// 		tmp[j] = buf;
	// 		// printf("%c\n", buf[i]);
	// 		printf("%s\n", tmp[j]);

	// 	}
	// }
		printf("i: %d\n", i);

		printf("tmp[j]: %s\n", tmp[0]);
		A.ratioA = ft_atof(tmp[1]);
		printf("ratio: %lf\n", A.ratioA);

		// color
		// while (*buf == ' ' || *buf == '\t')
		// 	buf++;
		// while (*buf != ',')
		// 	A.rgb.r = ft_atoi(buf);
		// printf("%d\n", A.rgb.r);

		// buf++;
		// A.rgb.g = ft_atoi(buf);
		// buf++;
		// A.rgb.b = ft_atoi(buf);
	// }

	free(tmp);
	return (d.nbA);
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

