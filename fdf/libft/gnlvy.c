/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlvy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:15:50 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/24 11:06:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "../fdf.h"

//nbchar = nombre de char lu
//str = nouvelle chaine de char
//buffer = chaine de caratere qui a ete lu

char	*get_next_line(int fd)
{
	char	*str;
	char	*buffer;
	int		nbchar;

	buffer = ft_calloc((2), sizeof(char));
	str = NULL;
	nbchar = read(fd, buffer, 1);
	if (nbchar > 0)
		str = ft_calloc((2), sizeof(char));
	while (nbchar > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
	nbchar = read(fd, buffer, 1);
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	free(buffer);
	return (str);
}
/*
int main()

{
    int fd;

    fd = open("/users/stgerard/testline", O_RDONLY);
    printf("%s", get_next_line(fd));
}
*/