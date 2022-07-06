/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:44:55 by stgerard          #+#    #+#             */
/*   Updated: 2022/07/06 16:56:37 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*xpm_to_img(t_env *e, char *path)
{
	char	*apath;
	void	*img;
	int		width;
	int		height;

	apath = ft_strjoin("./sprites/", path);
	img = mlx_xpm_file_to_image(e->mlx, apath, &width, &height);
	if (!img)
		ft_error("\x1B[31mError : invalid file.");
	return (img);
}

void	img_to_sprite(t_env *e, t_sprite **sprite, char *img, int c)
{
	t_sprite	*tmp;
	char		*filename;
	char		*xpm;
	int			num;
	int			i;

	*sprite = (t_sprite *)malloc(sizeof(t_sprite));
	tmp = *sprite;
	i = 0;
	while (i < c)
	{
		num = '0' + i;
		filename = ft_strjoin(img, (char *)&num);
		xpm = ft_strjoin(filename, ".xpm");
		tmp->img = xpm_to_img(e, xpm);
		free(filename);
		free(xpm);
		if (i != c - 1)
		{
			tmp->next = (t_sprite *)malloc(sizeof(t_sprite));
			tmp = tmp->next;
		}
		i++;
	}
	tmp->next = *sprite;
}
