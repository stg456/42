/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:27:31 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/04 14:35:36 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	confirmation(int pid)
{
	if (pid)
		ft_putstr("Received message\n");
}

void	send_mess(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr("Incorrect number of arguments\n");
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, confirmation) == SIG_ERR)
	{
		ft_putstr("cannot send a message\n");
		exit (1);
	}
	send_mess(pid, argv[2]);
	return (0);
}
