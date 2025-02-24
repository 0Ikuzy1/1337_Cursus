/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:20:38 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/06 08:16:23 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *str1, char *str2);
int		check_input(char *str, t_liste **stackA, t_liste **stackB);
int		get_input(t_liste **stackA, t_liste **stackB);
void	main_helper(t_liste **stackA, t_liste **stackB);
char	*ft_strjoin1(char *s1, char *s2);
int		check_sort1(t_liste **stackA);

#endif