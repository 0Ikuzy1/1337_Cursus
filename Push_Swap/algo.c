/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:24:10 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/30 18:53:20 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_pst(t_liste *stack, int i)
{
	t_liste	*tmp;
	int		j;

	tmp = stack;
	j = 0;
	while (tmp)
	{
		if (tmp->data == i)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}

int	get_idx_pst(t_liste *stack, int i)
{
	t_liste	*tmp;
	int		j;

	tmp = stack;
	j = 0;
	while (tmp)
	{
		if (tmp->index < i)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}

void	push_to_b(t_liste **stackA, t_liste **stackB, int p)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stackA);
	while (i < size)
	{
		if ((*stackA)->index <= i)
		{
			pb(stackA, stackB);
			rb(stackB);
			i++;
		}
		else if ((*stackA)->index <= (i + p))
		{
			pb(stackA, stackB);
			i++;
		}
		else if (get_idx_pst(*stackA, (i + p)) < ft_lstsize(*stackA) / 2)
			ra(stackA);
		else
			rra(stackA);
	}
	push_to_a(stackA, stackB);
}

void	push_to_a(t_liste **stackA, t_liste **stackB)
{
	int	highest;
	int	position;

	highest = maximum(stackB);
	position = get_highest_pst(*stackB, highest);
	while (ft_lstsize(*stackB) > 0)
	{
		if (highest == (*stackB)->data)
		{
			pa(stackA, stackB);
			if (ft_lstsize(*stackB) > 0)
			{
				highest = maximum(stackB);
				position = get_highest_pst(*stackB, highest);
			}
		}
		else
		{
			if (position <= (ft_lstsize(*stackB) / 2)
				&& highest != (*stackB)->data)
				rb(stackB);
			else
				rrb(stackB);
		}
	}
}
