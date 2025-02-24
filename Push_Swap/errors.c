/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:53:17 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/01 20:35:26 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] && str[i] == ' ')
	{
		if (str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
			|| (str[i] == '+' || str[i] == '-')))
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if ((i > 0 && str[i - 1] != ' ') || (str[i + 1] == '\0'
					|| str[i + 1] == ' '))
				return (1);
		}
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int *tab, int p)
{
	int	i;
	int	j;

	i = 0;
	while (i < (p - 1))
	{
		j = i + 1;
		while (j <= (p - 1))
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_stack(t_liste **stack)
{
	t_liste	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

long	atoi_check(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}
