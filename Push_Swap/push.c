/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:37:43 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/27 18:17:10 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_liste **stack1, t_liste **stack2)
{
	t_liste	*tmp;
	t_liste	*node1;
	t_liste	*node2;

	if (ft_lstsize(*stack1) == 0)
		return (1);
	node1 = *stack1;
	node2 = *stack2;
	tmp = node1->next;
	if (!stack2)
	{
		node2 = node1;
		node2->next = NULL;
	}
	else
	{
		node1->next = *stack2;
		*stack2 = node1;
	}
	*stack1 = tmp;
	return (0);
}

int	pb(t_liste **stackA, t_liste **stackB)
{
	if (push(stackA, stackB) == 1)
		return (1);
	ft_putstr_fd("pb", 1);
	return (0);
}

int	pa(t_liste **stackA, t_liste **stackB)
{
	if (push(stackB, stackA) == 1)
		return (1);
	ft_putstr_fd("pa", 1);
	return (0);
}
