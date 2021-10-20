/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:41:59 by mdaillet          #+#    #+#             */
/*   Updated: 2021/08/17 10:00:06 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *si, void *oldact)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static pid_t			cpid = 0;

	(void)oldact;
	if (!cpid)
		cpid = si->si_pid;
	c |= (sig == SIGUSR1);
	if (++bit == 8)
	{
		bit = 0;
		if (c == 0x00)
		{
			cpid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(cpid, SIGUSR1);
	}
	else
	{
		c = c << 1;
		kill(cpid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	s;

	ft_putstr_fd("\033[22;34mYour PID is : \033[0m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &s, 0);
	sigaction(SIGUSR2, &s, 0);
	while (1)
		pause();
	return (0);
}
