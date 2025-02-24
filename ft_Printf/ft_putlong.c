/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:02:58 by ozouine           #+#    #+#             */
/*   Updated: 2023/12/10 21:04:49 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlong(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
	{
		counter += ft_putlong(nb / 10);
		counter += ft_putlong(nb % 10);
	}
	else
		counter += ft_putchar(nb + 48);
	return (counter);
}
