/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:00:30 by ozouine           #+#    #+#             */
/*   Updated: 2023/12/10 21:08:02 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlong_base(unsigned long nb)
{
	unsigned long	i;
	int				counter;
	char			*base;

	counter = 0;
	base = "0123456789abcdef";
	i = ft_strlen(base);
	if (nb >= i)
	{
		counter += ft_putlong_base(nb / i);
		counter += ft_putlong_base(nb % i);
	}
	else
		counter += ft_putchar(base[nb]);
	return (counter);
}

int	ft_printadd(void *s)
{
	unsigned long	n;

	if (s == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		write(1, "0x", 2);
	n = (unsigned long)s;
	return (ft_putlong_base(n) + 2);
}
