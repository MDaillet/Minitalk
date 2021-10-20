/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:23:15 by mdaillet          #+#    #+#             */
/*   Updated: 2021/08/13 19:46:17 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
