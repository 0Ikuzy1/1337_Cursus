/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:33:53 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/28 11:34:15 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap(t_liste **stack)
{
	t_liste	*head;
	t_liste	*new_head;
	int		tmp_data;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	new_head = head->next;
	if (!head && !new_head)
		return (1);
	tmp_data = head->data;
	tmp_index = head->index;
	head->data = new_head->data;
	head->index = new_head->index;
	new_head->data = tmp_data;
	new_head->index = tmp_index;
	return (0);
}

int	sa(t_liste **stack)
{
	if (swap(stack) == 1)
		return (1);
	return (0);
}

int	sb(t_liste **stack)
{
	if (swap(stack) == 1)
		return (1);
	return (0);
}

int	ss(t_liste **stackA, t_liste **stackB)
{
	if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
		return (1);
	swap(stackA);
	swap(stackB);
	return (0);
}
