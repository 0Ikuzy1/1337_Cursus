/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:58:08 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/01 20:32:20 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + (nptr[i++] - 48);
	if (atoi_check(nb))
		return (2147483648);
	return (nb * sign);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*sort_tab(int *tab, int p)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (p - 1))
	{
		j = i + 1;
		while (j < p)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	indexing(t_liste **stack, int *tab, int p)
{
	t_liste	*tmp;
	int		i;

	i = 0;
	while (i < p)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->data == tab[i])
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
}
