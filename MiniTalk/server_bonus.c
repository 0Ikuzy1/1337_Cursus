/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:32:57 by ozouine           #+#    #+#             */
/*   Updated: 2024/03/21 20:18:49 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	sigaction_a(int signal, siginfo_t *info, void *str)
{
	static int	b;
	static char	msg;

	(void) str;
	if (signal == SIGUSR1)
		msg = (msg << 1) | 1;
	else if (signal == SIGUSR2)
		msg = (msg << 1);
	b++;
	if (b == 8)
	{
		write(1, &msg, 1);
		if (!msg)
		{
			usleep(300);
			kill(info->si_pid, SIGUSR1);
		}
		b = 0;
		msg = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					id;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sigaction_a;
	if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_putstr("Error");
		exit (1);
	}
	id = getpid();
	ft_putnbr(id);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
