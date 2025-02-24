/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:25:08 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/06 12:21:01 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_var	v;

	if (ac > 1)
	{
		v.stacka = NULL;
		v.stackb = NULL;
		v.i = 1;
		v.j = 1;
		v.join = NULL;
		while (v.i < ac)
		{
			if (check_digits(av[v.i]) == 1 || check_spaces(av[v.i]) == 1)
				return (ft_putstr_fd("Error", 1), 1);
			v.i++;
		}
		while (v.j < ac)
		{
			v.str = v.join;
			v.join = ft_strjoin(v.join, av[v.j++]);
			free(v.str);
		}
		if (processing(&v.stacka, v.join) == 1)
			sorting(&v.stacka, &v.stackb);
		(free_stack(&v.stacka), free_stack(&v.stacka));
	}
}
