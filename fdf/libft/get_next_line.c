/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:28:47 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/24 11:02:55 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char	*lect(int fd, char *txt)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	i++;
	while (i != 0 && !ft_strchr(txt, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (0);
		}
		str[i] = '\0';
		txt = ft_strjoin(txt, str);
	}
	free(str);
	return (txt);
}

static char	*ligne(char *txt)
{
	int		i;
	char	*str;

	i = 0;
	if (txt[i] == '\0')
		return (0);
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
	{
		str[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		str[i] = txt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*gard(char *txt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	if (txt[i] == '\0')
	{
		free(txt);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(txt) - i + 1));
	if (!str)
		return (0);
	i++;
	while (txt[i] != '\0')
	{
		str[j++] = txt[i++];
	}
	str[j] = '\0';
	free(txt);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	txt = lect(fd, txt);
	if (!txt)
		return (0);
	str = ligne(txt);
	txt = gard(txt);
	return (str);
}
