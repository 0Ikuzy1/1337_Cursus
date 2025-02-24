/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:18:36 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/24 20:31:36 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died_or_not(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	if (get_time() - philo->lst_meal > philo->input->time_to_die)
	{
		pthread_mutex_lock(philo->input->dead);
		philo->input->is_dead = 1;
		pthread_mutex_unlock(philo->mutex);
		pthread_mutex_unlock(philo->input->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

int	check_flow(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->philos_nbr)
	{
		if (died_or_not(&philo[i]))
		{
			printf("%ld %d died\n", get_time() - philo[i].start_time,
				philo[i].id);
			return (1);
		}
		pthread_mutex_lock(philo[i].mutex);
		if (philo->input->meals_nbr
			&& philo[i].count_meal >= philo->input->meals_nbr)
		{
			pthread_mutex_unlock(philo[i].mutex);
			return (1);
		}
		pthread_mutex_unlock(philo[i].mutex);
		i++;
	}
	return (0);
}
