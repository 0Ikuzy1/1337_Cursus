/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_fcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:03:08 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/24 20:30:19 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simflow(t_inp *input, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < input->philos_nbr)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	free_mutex(pthread_mutex_t *mtx, t_inp *input)
{
	int	i;

	i = 0;
	while (i < input->philos_nbr)
	{
		pthread_mutex_destroy(&mtx[i]);
		i++;
	}
}
