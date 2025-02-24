/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:33:28 by ozouine           #+#    #+#             */
/*   Updated: 2024/03/24 12:43:52 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

long		ft_atoi(const char *str);
void		ft_putnbr(long long n);
void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_isdigit(char *str);

#endif