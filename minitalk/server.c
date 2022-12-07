/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:27:12 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/04 14:35:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	server_handler(int sig, siginfo_t *info, void *nullpointer)
{
	static pid_t			client_pid = 0;
	static int				i = 8;
	static unsigned char	c = 0;

	(void)nullpointer;
	client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	i--;
	if (i == 0)
	{
		if (c != 0)
			ft_putchar(c);
		else
		{
			kill(client_pid, SIGUSR1);
			ft_putchar('\n');
		}
		c = 0;
		i = 8;
	}
	else
		c <<= 1;
}

int	start_server(void)
{
	static pid_t		pid = 0;
	struct sigaction	sig;

	pid = getpid();
	ft_putstr("pid is :");
	ft_putnbr(pid);
	ft_putchar('\n');
	sig.sa_sigaction = server_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) != 0
		|| (sigaction(SIGUSR2, &sig, NULL) != 0))
	{
		ft_putstr("Error: Unable to receive message\n");
		return (0);
	}
	while (1)
		pause();
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Error: the server must not have any arguments\n");
		return (0);
	}
	start_server();
	return (0);
}
