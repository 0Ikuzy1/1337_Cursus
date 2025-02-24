/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:45:53 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/06 11:06:06 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_liste **stackA)
{
	t_liste	*tmp;

	tmp = *stackA;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	processing(t_liste **stackA, char *join)
{
	char	**split;
	int		*tab;
	int		i;
	int		s;

	s = 0;
	split = ft_split(join, ' ');
	i = ft_strslen(split);
	tab = (int *)malloc(sizeof(int) * i);
	while (s < i)
	{
		if (ft_atoi(split[s]) == 2147483648)
			return (ft_putstr_fd("Error", 2), exit(1), 1);
		tab[s] = ft_atoi(split[s]);
		s++;
	}
	if (check_double(tab, i) == 1)
		return (ft_putstr_fd("Error", 1), exit(1), 1);
	fill_stack(stackA, tab, i);
	tab = sort_tab(tab, i);
	indexing(stackA, tab, i);
	ft_free(split, i, tab, join);
	if (check_sort(stackA) == 1)
		return (1);
	return (0);
}

void	sorting(t_liste **stackA, t_liste **stackB)
{
	if (ft_lstsize(*stackA) == 2)
		sorting_2(stackA);
	else if (ft_lstsize(*stackA) == 3)
		sorting_3(stackA);
	else if (ft_lstsize(*stackA) == 4)
		sorting_4(stackA, stackB);
	else if (ft_lstsize(*stackA) == 5)
		sorting_5(stackA, stackB);
	else if (ft_lstsize(*stackA) > 5)
	{
		if (ft_lstsize(*stackA) < 250)
			push_to_b(stackA, stackB, 15);
		else
			push_to_b(stackA, stackB, 40);
	}
}
