/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:33:12 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/25 09:47:55 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (eat(philo))
			break ;
		print_and_sleep(philo);
		pthread_mutex_lock(philo->mutex);
		pthread_mutex_lock(philo->input->dead);
		if (philo->input->is_dead || (philo->input->meals_nbr
				&& philo->count_meal >= philo->input->meals_nbr))
		{
			pthread_mutex_unlock(philo->mutex);
			pthread_mutex_unlock(philo->input->dead);
			break ;
		}
		pthread_mutex_unlock(philo->mutex);
		pthread_mutex_unlock(philo->input->dead);
		usleep(500);
	}
	return (NULL);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork", get_time() - philo->start_time);
	if (philo->input->philos_nbr == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork", get_time() - philo->start_time);
	ft_print(philo, "is eating", get_time() - philo->start_time);
	pthread_mutex_lock(philo->mutex);
	philo->count_meal++;
	philo->lst_meal = get_time();
	pthread_mutex_unlock(philo->mutex);
	ft_sleep(philo->input->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	print_and_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping", get_time() - philo->start_time);
	ft_sleep(philo->input->time_to_sleep, philo);
	ft_print(philo, "is thinking", get_time() - philo->start_time);
}

void	ft_print(t_philo *philo, char *s, long time)
{
	pthread_mutex_lock(philo->input->dead);
	if (philo->input->is_dead)
	{
		pthread_mutex_unlock(philo->input->dead);
		return ;
	}
	printf("%ld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(philo->input->dead);
}

void	ft_sleep(long time, t_philo *philo)
{
	long	start;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(philo->input->dead);
		if (philo->input->is_dead)
		{
			pthread_mutex_unlock(philo->input->dead);
			break ;
		}
		pthread_mutex_unlock(philo->input->dead);
		if (get_time() - start >= time)
			break ;
		usleep(200);
	}
}
