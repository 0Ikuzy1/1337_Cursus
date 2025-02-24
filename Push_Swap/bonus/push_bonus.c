/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:37:43 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/28 11:34:42 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	return (0);
}

int	pa(t_liste **stackA, t_liste **stackB)
{
	if (push(stackB, stackA) == 1)
		return (1);
	return (0);
}
