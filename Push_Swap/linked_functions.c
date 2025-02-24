/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:31:25 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/28 12:23:44 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_liste *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_liste	*ft_lstlast(t_liste *lst)
{
	t_liste	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	fill_stack(t_liste **stack, int *tab, int p)
{
	int	i;

	i = 0;
	while (p > i)
		ft_lstadd_back(stack, ft_lstnew(tab[i++]));
}

void	ft_lstadd_back(t_liste **lst, t_liste *new)
{
	t_liste	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	if (tmp)
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*lst = new;
}

t_liste	*ft_lstnew(int content)
{
	t_liste	*node;

	node = malloc(sizeof(t_liste));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}
