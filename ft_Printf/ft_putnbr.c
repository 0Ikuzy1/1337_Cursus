/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:03:03 by ozouine           #+#    #+#             */
/*   Updated: 2023/12/10 21:05:23 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		counter;

	counter = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		counter += write(1, "-", 1);
	}
	if ((nb / 10) > 0)
		counter += ft_putnbr((nb / 10));
	counter += ft_putchar(nb % 10 + 48);
	return (counter);
}
