/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:03:01 by ozouine           #+#    #+#             */
/*   Updated: 2023/12/10 21:05:03 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char c)
{
	unsigned long	i;
	unsigned long	nb;
	int				counter;
	char			*base;

	counter = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	nb = (unsigned long)nbr;
	i = ft_strlen(base);
	if (nb >= i)
	{
		counter += ft_putnbr_base((unsigned int)nb / i, c);
		counter += ft_putnbr_base((unsigned int)nb % i, c);
	}
	else
	{
		ft_putchar(base[nb]);
		counter++;
	}
	return (counter);
}
