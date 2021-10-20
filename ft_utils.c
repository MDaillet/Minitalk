/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:24:57 by mdaillet          #+#    #+#             */
/*   Updated: 2021/08/13 20:10:23 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			write(fd, &str[i], 1);
}

static int	ft_isspace(int c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	size_t	i;
	int		n;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			n = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (int)s[i] - 48;
		i++;
	}
	return (n * neg);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ui;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ui = n;
	if (ui >= 10)
	{
		ft_putnbr_fd((ui / 10), fd);
		ft_putchar_fd((ui % 10) + 48, fd);
	}
	else
		ft_putchar_fd(ui + 48, fd);
}
