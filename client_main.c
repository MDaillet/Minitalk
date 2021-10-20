/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:09:00 by mdaillet          #+#    #+#             */
/*   Updated: 2021/10/19 13:59:29 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_term(pid_t spid)
{
	int	bit;

	bit = 0;
	while (bit++ != 8)
	{
		usleep(100);
		kill(spid, SIGUSR2);
	}
	exit(0);
}

void	ft_send(char *s, pid_t pid)
{
	static int				bit = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			spid;

	if (s)
	{
		str = s;
		spid = pid;
		c = *str;
	}
	if (!bit)
	{
		bit = 8;
		c = *(++str);
		if (!c)
			ft_term(spid);
	}
	if (c && c >> --bit & 1)
		kill(spid, SIGUSR1);
	else if (c)
		kill(spid, SIGUSR2);
}

void	ft_feedback(int signal, siginfo_t *si, void *oldact)
{
	static int	bytes = 0;

	(void)si;
	(void)oldact;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("\r\033[22;34mArrived Bytes : \033[0m", 1);
		ft_putnbr_fd(++bytes, 1);
	}
	ft_send(0, 0);
}

int	main(int ac, char **av)
{
	struct sigaction	s;

	if (ac != 3)
	{
		ft_putstr_fd("\r\033[22;34m./client [Server PID] [Message]\n\033[0m", 1);
		return (1);
	}
	if (!ft_atoi(av[1]))
	{
		ft_putstr_fd("\r\033[22;34mPID cannot be 0.\n\033[0m", 1);
		exit(0);
	}
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = ft_feedback;
	sigaction(SIGUSR1, &s, 0);
	sigaction(SIGUSR2, &s, 0);
	ft_putstr_fd("\033[22;34mSending : \033[0m", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putstr_fd("\033[22;34m bytes.\n\033[0m", 1);
	ft_send(av[2], ft_atoi(av[1]));
	while (1)
		pause();
	return (0);
}
