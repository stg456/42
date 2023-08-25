/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:18 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/22 12:04:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	cmpt2(char *buf, t_data *d)
{
	if (*buf != '\0')
	{
		if (*buf == '\n')
		{};
		if (ft_strncmp(buf, "A", 1) == 0)
			d->nbA +=1;
		else if (ft_strncmp(buf, "C", 1) == 0)
			d->nbC += 1;
		else if (ft_strncmp(buf, "L", 1) == 0)
			d->nbL += 1;
		else if (ft_strncmp(buf, "sp", 2) == 0)
			d->nbsp +=1;
		else if (ft_strncmp(buf, "pl", 2) == 0)
			d->nbpl += 1;
		else if (ft_strncmp(buf, "cy", 2) == 0)
			d->nbcy += 1;
		else
		{
			printf("buf: %s", buf);
			close(d->fd);
			ft_error("Error:\nincorrect data\n");
		}
	}
}

void	cmpt(t_data *d, char *filename)
{
	char	*buf;

	d->nbA = 0;
	d->nbC = 0;
	d->nbcy = 0;
	d->nbL = 0;
	d->nbpl = 0;
	d->nbsp = 0;
	d->fd = open(filename, O_RDONLY);
	if (d->fd < 0)
	{
		close(d->fd);
		ft_error("\x1B[31mError\nInvalid file\n");
	}
	buf = get_next_line(d->fd);
	if (!buf)
		ft_error("Error\nfile is empty\n");
	while (buf)
	{
		cmpt2(buf, d);
		free(buf);
		buf = NULL;
		buf = get_next_line(d->fd);
	}
	close(d->fd);
	if (d->nbA != 1 || d->nbC != 1 || d->nbL != 1)
		ft_error("Error\nWrong number of A, C and/or L\n");
}