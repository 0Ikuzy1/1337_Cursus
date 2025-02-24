/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:32:51 by ozouine           #+#    #+#             */
/*   Updated: 2024/03/24 12:40:31 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	send(int pid, char c)
{
	int	error;
	int	counter;

	error = 0;
	counter = 7;
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep (300);
		counter--;
		if (error == -1)
			ft_putstr("Error");
	}
}

void	done(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("sent succesfully");
	exit (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*str;

	pid = 0;
	if (ac == 3 && ft_isdigit(av[1]))
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0 || pid > 2147483647)
		{
			ft_putstr("PID incorrect");
			exit(1);
		}
		str = av[2];
		while (str[i])
			send(pid, str[i++]);
		send(pid, '\0');
		signal(SIGUSR1, done);
		while (1)
			pause();
	}
	else
		ft_putstr("invalide input");
	return (0);
}
