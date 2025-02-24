/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:06 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/30 15:50:42 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_mlx *lbx)
{
	lbx->count_mv++;
	ft_printf("%d\n", lbx->count_mv);
}

void	count_colls(t_mlx *lbx)
{
	int	s;
	int	x;

	lbx->count_coll = 0;
	s = 0;
	while (lbx->map[s])
	{
		x = 0;
		while (lbx->map[s][x])
		{
			if (lbx->map[s][x] == 'C')
			{
				lbx->count_coll++;
			}
			x++;
		}
		s++;
	}
}

void	player_position(t_mlx *lbx, int *a, int *b)
{
	int	s;
	int	x;

	s = 0;
	while (lbx->map[s])
	{
		x = 0;
		while (lbx->map[s][x])
		{
			if (lbx->map[s][x] == 'P')
			{
				*a = s;
				*b = x;
			}
			x++;
		}
		s++;
	}
}

int	move_player(t_mlx *lbx, int yp, int xp)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	player_position(lbx, &a, &b);
	if (lbx->map[a + yp][b + xp] == '1')
		return (0);
	else if (lbx->map[a + yp][b + xp] == 'C')
	{
		lbx->count_coll--;
		count_moves(lbx);
	}
	else if (lbx->map[a + yp][b + xp] == 'E' && lbx->count_coll != 0)
		return (0);
	else if (lbx->map[a + yp][b + xp] == 'E' && lbx->count_coll == 0)
		return (count_moves(lbx), printf("congrats you won\n"),
			destroy(lbx), exit(0), 0);
	lbx->map[a][b] = '0';
	lbx->map[a + yp][b + xp] = 'P';
	mlx_clear_window(lbx->mlx, lbx->mlx_win);
	if (yp != 0 || xp != 0)
		count_moves(lbx);
	return (0);
}

int	move_keys(int keycode, t_mlx *lbx, t_var *v)
{
	int	yp;
	int	xp;

	yp = 0;
	xp = 0;
	if (keycode == 65307)
	{
		destroy(lbx);
		closenkill1(lbx, "you quit the game", 0, v);
	}
	if (keycode == 65362 || keycode == 119)
		yp = -1;
	else if (keycode == 65364 || keycode == 115)
		yp = 1;
	else if (keycode == 65363 || keycode == 100)
		xp = 1;
	else if (keycode == 65361 || keycode == 97)
		xp = -1;
	move_player(lbx, yp, xp);
	draw_map(lbx, 0, 0);
	return (0);
}
