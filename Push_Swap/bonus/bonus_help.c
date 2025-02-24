/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:59:05 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/06 09:33:22 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_input(char *str, t_liste **stackA, t_liste **stackB)
{
	if (!ft_strcmp(str, "pa\n"))
		return (pa(stackA, stackB), 0);
	else if (!ft_strcmp(str, "pb\n"))
		return (pb(stackA, stackB), 0);
	else if (!ft_strcmp(str, "sa\n"))
		return (sa(stackA), 0);
	else if (!ft_strcmp(str, "sb\n"))
		return (sb(stackB), 0);
	else if (!ft_strcmp(str, "ss\n"))
		return (ss(stackA, stackB), 0);
	else if (!ft_strcmp(str, "ra\n"))
		return (ra(stackA), 0);
	else if (!ft_strcmp(str, "rb\n"))
		return (rb(stackB), 0);
	else if (!ft_strcmp(str, "rr\n"))
		return (rr(stackA, stackB), 0);
	else if (!ft_strcmp(str, "rra\n"))
		return (rra(stackA), 0);
	else if (!ft_strcmp(str, "rrb\n"))
		return (rrb(stackB), 0);
	else if (!ft_strcmp(str, "rrr\n"))
		return (rrr(stackA, stackB), 0);
	else
		return (1);
}

int	get_input(t_liste **stackA, t_liste **stackB)
{
	char	*temp;

	temp = get_next_line(0);
	if (temp == NULL)
	{
		if (check_sort1(stackA))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		return (free_stack(stackA), free_stack(stackB), free(temp), exit(0), 0);
	}
	while (temp != NULL)
	{
		if (temp[0] == '\n')
			return (free(temp), 0);
		if (check_input(temp, stackA, stackB))
			return (free(temp), 0);
		free(temp);
		temp = get_next_line(0);
	}
	return (1);
}

void	main_helper(t_liste **stackA, t_liste **stackB)
{
	if (!get_input(stackA, stackB))
		return (write(2, "Error\n", 6), free_stack(stackA), free_stack(stackB),
			exit(1));
	if (check_sort1(stackA) && ft_lstsize(*stackB) == 0)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free_stack(stackA);
	if (stackB != NULL)
		free_stack(stackB);
}
