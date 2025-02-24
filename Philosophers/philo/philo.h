/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:58:13 by ozouine           #+#    #+#             */
/*   Updated: 2024/12/24 20:30:07 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_inp
{
	pthread_mutex_t		*dead;
	int					philos_nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_nbr;
	int					is_dead;
}						t_inp;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*mutex;
	long				start_time;
	long				count_meal;
	long				lst_meal;
	t_inp				*input;

}						t_philo;

t_inp			*input_parse(char **av);
void			input_parse1(t_inp *data, char **av);
long			ft_atoi(const char *str);
int				check_num(char *str);
int				check_args(char **av);
long			get_time(void);
int				died_or_not(t_philo *philo);
int				check_flow(t_philo *philo);
int				innit_philos(t_inp *input);
pthread_mutex_t	*mtx_mnp(t_inp *input);
void			philosopher(t_inp *input, pthread_mutex_t *forks,
					pthread_mutex_t *boxes, t_philo *philo);
void			var(t_inp *input, int *i, pthread_mutex_t *boxes,
					t_philo *philo);
void			simflow(t_inp *input, t_philo *philo);
void			free_mutex(pthread_mutex_t *mtx, t_inp *input);
void			*routine(void *arg);
int				eat(t_philo *philo);
void			print_and_sleep(t_philo *philo);
void			ft_print(t_philo *philo, char *s, long time);
void			ft_sleep(long time, t_philo *philo);

#endif