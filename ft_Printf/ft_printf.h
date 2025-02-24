/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:07:47 by ozouine           #+#    #+#             */
/*   Updated: 2023/12/10 21:07:48 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putnbr_base(int nbr, char c);
int		ft_printadd(void *s);
int		ft_putlong(unsigned int nb);

#endif