/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:35:07 by ozouine           #+#    #+#             */
/*   Updated: 2024/03/28 14:00:06 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_liste **stack)
{
	t_liste	*top;
	t_liste	*last;

	if (ft_lstsize(*stack) < 2)
		return (1);
	top = *stack;
	last = ft_lstlast(top);
	*stack = top->next;
	last->next = top;
	top->next = NULL;
	return (0);
}

int	ra(t_liste **stackA)
{
	if (rotate(stackA) == 1)
		return (1);
	ft_putstr_fd("ra", 1);
	return (0);
}

int	rb(t_liste **stackB)
{
	if (rotate(stackB) == 1)
		return (1);
	ft_putstr_fd("rb", 1);
	return (0);
}

int	rr(t_liste **stackA, t_liste **stackB)
{
	if (ft_lstsize(*stackA) < 2 || ft_lstsize(*stackB) < 2)
		return (1);
	rotate(stackA);
	rotate(stackB);
	ft_putstr_fd("rr", 1);
	return (0);
}
