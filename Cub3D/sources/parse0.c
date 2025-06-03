/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:58:36 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:10:44 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	is_valid_tile(char c)
{
	return (c == '0' || ft_strchr("NSEW", c));
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || ft_strchr("NSEW", c));
}

int	compaire_data(t_map *d, int i, int j)
{
	return (d->map_arr[i - 1][j] == ' ' || d->map_arr[i + 1][j] == ' '
		|| d->map_arr[i][j - 1] == ' ' || d->map_arr[i][j + 1] == ' ');
}

int	is_map_surrounded(t_map *d)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < d->cols)
	{
		j = 0;
		while (j < d->rows)
		{
			c = d->map_arr[i][j];
			if (!is_valid_char(c))
				return (write(1, "Invalid character\n", 18), 0);
			if (is_valid_tile(c))
			{
				if (i == 0 || j == 0 || i == d->cols - 1 || j == d->rows - 1)
					return (write(1, "Open edge\n", 10), 0);
				if (compaire_data(d, i, j))
					return (write(1, "Open space\n", 11), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
