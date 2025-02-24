/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:38:59 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/22 15:21:53 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_liste **stack)
{
	t_liste	*top;
	t_liste	*last;

	if (ft_lstsize(*stack) < 2)
		return (1);
	top = *stack;
	last = ft_lstlast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_liste **stackA)
{
	if (rev_rotate(stackA) == 1)
		return (1);
	ft_putstr_fd("rra", 1);
	return (0);
}

int	rrb(t_liste **stackB)
{
	if (rev_rotate(stackB) == 1)
		return (1);
	ft_putstr_fd("rrb", 1);
	return (0);
}

int	rrr(t_liste **stackA, t_liste **stackB)
{
	if (ft_lstsize(*stackA) < 2 || ft_lstsize(*stackA) < 2)
		return (1);
	rev_rotate(stackA);
	rev_rotate(stackB);
	ft_putstr_fd("rrr", 1);
	return (0);
}
