/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:21:41 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/30 15:50:11 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	closenkill1(t_mlx *lbx, char *str, int i, t_var *v)
{
	(void)v;
	ft_printf("%s\n", str);
	if (lbx->map != NULL)
		ft_free(lbx->map);
	if (lbx->map_dup != NULL)
		ft_free(lbx->map_dup);
	exit(i);
}

int	ft_exit(t_mlx *lbx, t_var *v)
{
	destroy(lbx);
	closenkill1(lbx, "you quit the game", 0, v);
	return (0);
}

void	ft_floodfill(t_mlx *lbx, int x, int y)
{
	if (x < 0 || y < 0 || x >= lbx->i || y >= lbx->j)
		return ;
	if (lbx->map_dup[x][y] == '1' || lbx->map_dup[x][y] == 'O')
		return ;
	if (lbx->map_dup[x][y] == 'E')
	{
		lbx->map_dup[x][y] = 'O';
		return ;
	}
	lbx->map_dup[x][y] = 'O';
	ft_floodfill(lbx, (x + 1), y);
	ft_floodfill(lbx, (x - 1), y);
	ft_floodfill(lbx, x, (y + 1));
	ft_floodfill(lbx, x, (y - 1));
}

void	ft_check_floodfill(t_mlx *lbx, char **map, t_var *v)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				closenkill1(lbx, "Player can't reach the Exit", 1, v);
			else if (map[i][j] == 'C')
				closenkill1(lbx, "Player can't reach all Collectibles", 1, v);
			j++;
		}
		i++;
	}
}

void	ft_validate_path(t_mlx *lbx, t_var *v)
{
	int	x;
	int	y;

	player_position(lbx, &x, &y);
	ft_floodfill(lbx, x, y);
	ft_check_floodfill(lbx, lbx->map_dup, v);
}
