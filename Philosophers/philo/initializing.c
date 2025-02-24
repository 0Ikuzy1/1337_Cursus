/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:45:13 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/24 20:32:12 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	innit_philos(t_inp *input)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*boxes;

	forks = mtx_mnp(input);
	boxes = mtx_mnp(input);
	philo = malloc(sizeof(t_philo) * input->philos_nbr);
	if (!philo)
		return (1);
	philosopher(input, forks, boxes, philo);
	while (1)
	{
		if (check_flow(philo))
			break ;
	}
	simflow(input, philo);
	free_mutex(boxes, input);
	free_mutex(forks, input);
	free(philo);
	free(forks);
	free(boxes);
	return (0);
}

pthread_mutex_t	*mtx_mnp(t_inp *input)
{
	int				i;
	pthread_mutex_t	*mtx;

	mtx = malloc(sizeof(pthread_mutex_t) * input->philos_nbr);
	i = 0;
	while (i < input->philos_nbr)
	{
		pthread_mutex_init(&mtx[i], NULL);
		i++;
	}
	return (mtx);
}

void	philosopher(t_inp *input, pthread_mutex_t *forks,
		pthread_mutex_t *boxes, t_philo *philo)
{
	int		i;
	long	start;

	start = get_time();
	i = 0;
	while (i < input->philos_nbr)
	{
		var(input, &i, boxes, philo);
		philo[i].count_meal = 0;
		philo[i].start_time = start;
		philo[i].lst_meal = start;
		if (i % 2 == 0)
		{
			philo[i].left_fork = &forks[(i + 1) % input->philos_nbr];
			philo[i].right_fork = &forks[i];
		}
		else
		{
			philo[i].right_fork = &forks[(i + 1) % input->philos_nbr];
			philo[i].left_fork = &forks[i];
		}
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			printf("Error: Creating of threads failed\n");
		i++;
	}
}

void	var(t_inp *input, int *i, pthread_mutex_t *boxes, t_philo *philo)
{
	philo[*i].id = (*i) + 1;
	philo[*i].input = input;
	philo[*i].mutex = &boxes[*i];
}
