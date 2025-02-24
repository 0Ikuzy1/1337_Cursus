/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:35:07 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/28 11:34:37 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	return (0);
}

int	rb(t_liste **stackB)
{
	if (rotate(stackB) == 1)
		return (1);
	return (0);
}

int	rr(t_liste **stackA, t_liste **stackB)
{
	if (ft_lstsize(*stackA) < 2 || ft_lstsize(*stackB) < 2)
		return (1);
	rotate(stackA);
	rotate(stackB);
	return (0);
}
