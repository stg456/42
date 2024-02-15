/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:55:05 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/10 16:31:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	convert_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**convert_argv(int argc, char **argv)
{
	if (argc >= 3)
		argv = shift_array(argc, argv);
	else if (argc < 3)
		argv = ft_split(argv[1], ' ');
	return (argv);
}

void	push_swap_error(t_struct *list)
{
	free(list);
	write(2, "Error\n", 6);
}

t_struct	*push_swap_struct(int argc, char **argv)
{
	t_struct	*list;
	int			i;

	i = 0;
	list = (t_struct *)malloc(sizeof(t_struct));
	if (!list)
		push_swap_error(list);
	ft_bzero(list, sizeof(t_struct));
	list->len_a = argc;
	list->len_b = 0;
	list->stack_a = (int *)malloc(sizeof(int) * argc);
	if (!list->stack_a)
		push_swap_error(list);
	list->stack_b = (int *)malloc(sizeof(int) * argc);
	if (!list->stack_b)
		push_swap_error(list);
	while (i < argc)
	{
		list->stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	list->max_length = list->len_a;
	return (list);
}
/*
void	print_list(t_struct *list)
{
	int	i;

	i = 0;
	while (i < list->len_a)
	{
		ft_printf("%i\n", list->stack_a[i]);
		++i;
	}
}
*/
/*	print_list(list); juste avant le free pour le test */

int	main(int argc, char **argv)
{
	t_struct	*list;

	if (argc < 2)
		return (0);
	if (!check_start(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		argv = convert_argv(argc, argv);
		argc = convert_argc(argv);
		list = push_swap_struct(argc, argv);
	}
	push_swap_algo(list);
	free(list);
	return (0);
}
