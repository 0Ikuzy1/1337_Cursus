/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:29:03 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/30 15:07:22 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_img(t_mlx *lbx, t_var *v)
{
	int	width;
	int	height;

	lbx->ground = mlx_xpm_file_to_image(lbx->mlx, "structures/ground.xpm",
			&width, &height);
	if (lbx->ground == NULL)
		closenkill1(lbx, "Ground Xpm File Not found", 1, v);
	lbx->coll = mlx_xpm_file_to_image(lbx->mlx, "structures/diamond.xpm",
			&width, &height);
	if (lbx->coll == NULL)
		closenkill1(lbx, "Collectible Xpm File Not found", 1, v);
	lbx->player = mlx_xpm_file_to_image(lbx->mlx, "structures/player.xpm",
			&width, &height);
	if (lbx->player == NULL)
		closenkill1(lbx, "Player Xpm File Not found", 1, v);
	lbx->exit = mlx_xpm_file_to_image(lbx->mlx, "structures/closed_exit.xpm",
			&width, &height);
	if (lbx->exit == NULL)
		closenkill1(lbx, "Exit Xpm File Not found", 1, v);
	lbx->wall = mlx_xpm_file_to_image(lbx->mlx, "structures/wall.xpm",
			&width, &height);
	if (lbx->wall == NULL)
		closenkill1(lbx, "Wall Xpm File Not found", 1, v);
}

void	draw_map(t_mlx *lbx, int i, int j)
{
	while (lbx->map[i])
	{
		j = 0;
		while (lbx->map[i][j])
		{
			mlx_put_image_to_window(lbx->mlx, lbx->mlx_win, lbx->ground, j * 30,
				i * 30);
			if (lbx->map[i][j] == 'P')
				mlx_put_image_to_window(lbx->mlx, lbx->mlx_win, lbx->player, j
					* 30, i * 30);
			if (lbx->map[i][j] == 'E')
				mlx_put_image_to_window(lbx->mlx, lbx->mlx_win, lbx->exit, j
					* 30, i * 30);
			if (lbx->map[i][j] == 'C')
				mlx_put_image_to_window(lbx->mlx, lbx->mlx_win, lbx->coll, j
					* 30, i * 30);
			if (lbx->map[i][j] == '1')
				mlx_put_image_to_window(lbx->mlx, lbx->mlx_win, lbx->wall, j
					* 30, i * 30);
			j++;
		}
		i++;
	}
}
