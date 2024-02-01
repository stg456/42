/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:43:09 by stgerard          #+#    #+#             */
/*   Updated: 2022/04/19 17:35:14 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**shift_array(int argc, char **argv)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * argc);
	while (argv[i])
	{
		tmp[i] = ft_strdup(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		tmp[i] = argv[i + 1];
		tmp[i + 1] = argv[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	doublon(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && j != i)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_start(int argc, char **argv)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (argc >= 3)
		argv = shift_array(argc, argv);
	else if (argc < 3)
		argv = ft_split(argv[1], ' ');
	while (argv[c] != 0)
		c++;
	while (i < c)
	{
		if (!check_digit(argv[i]) || !ft_islonglong(argv[i]))
			return (0);
		i++;
	}
	if (!doublon(c, argv))
	{
		free(argv);
		return (0);
	}
	free(argv);
	return (1);
}
