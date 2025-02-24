/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:02:39 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/24 20:31:14 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_inp	*input_parse(char **av)
{
	t_inp	*input;

	input = malloc(sizeof(t_inp));
	if (!input)
		return (NULL);
	if ((ft_atoi(av[1]) > INT_MAX) || (ft_atoi(av[2]) > INT_MAX)
		|| (ft_atoi(av[3]) > INT_MAX) || (ft_atoi(av[4]) > INT_MAX)
		|| (av[5] && ft_atoi(av[5]) == 0))
	{
		printf("Error: Wrong arguments\n");
		return (NULL);
	}
	input->philos_nbr = ft_atoi(av[1]);
	if (!input->philos_nbr)
		return (NULL);
	input_parse1(input, av);
	input->meals_nbr = 0;
	if (av[5] && ft_atoi(av[5]) < INT_MAX)
		input->meals_nbr = ft_atoi(av[5]);
	input->is_dead = 0;
	input->dead = malloc(sizeof(pthread_mutex_t));
	if (!input->dead)
		return (NULL);
	pthread_mutex_init(input->dead, NULL);
	return (input);
}

void	input_parse1(t_inp *input, char **av)
{
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_inp	*input;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (check_args(av))
	{
		printf("Error: Wrong arguments\n");
		return (1);
	}
	input = input_parse(av);
	if (!input)
	{
		printf("Error: Data returned NULL\n");
		return (1);
	}
	innit_philos(input);
	pthread_mutex_destroy(input->dead);
	free(input->dead);
	free(input);
	return (0);
}
