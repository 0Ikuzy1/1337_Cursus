/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:40:49 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 22:41:06 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	check_collision(t_data *cub3d)
{
	int		map_x;
	int		map_y;
	double	right_edge;
	double	bottom_edge;

	map_x = (int)cub3d->player_pos.x;
	map_y = (int)cub3d->player_pos.y;
	right_edge = (cub3d->player_pos.x + PLAYER_SIZE);
	bottom_edge = (cub3d->player_pos.y + PLAYER_SIZE);
	return (cub3d->map.map_arr[map_y][map_x] == 1
		|| cub3d->map.map_arr[map_y][(int)right_edge] == 1
		|| cub3d->map.map_arr[(int)bottom_edge][map_x] == 1
		|| cub3d->map.map_arr[(int)bottom_edge][(int)right_edge] == 1);
}

void	move_player(t_data *cub3d, int keysym)
{
	if (keysym == XK_a)
		cub3d->player_pos = vector_add(cub3d->player_pos,
				vector_multiply(vector_rotate(cub3d->player_dir, 90), -STEP));
	else if (keysym == XK_d)
		cub3d->player_pos = vector_add(cub3d->player_pos,
				vector_multiply(vector_rotate(cub3d->player_dir, 90), STEP));
	else if (keysym == XK_w)
		cub3d->player_pos = vector_add(cub3d->player_pos,
				vector_multiply(cub3d->player_dir, STEP));
	else if (keysym == XK_s)
		cub3d->player_pos = vector_add(cub3d->player_pos,
				vector_multiply(cub3d->player_dir, -STEP));
}

void	player_movement(t_data *cub3d, int keysym)
{
	t_vector	old_pos;

	old_pos = cub3d->player_pos;
	move_player(cub3d, keysym);
	if (check_collision(cub3d))
		cub3d->player_pos = old_pos;
	else
	{
		cub3d->camera.x = cub3d->player_pos.x;
		cub3d->camera.y = cub3d->player_pos.y;
	}
}

void	update_direction(t_data *cub3d)
{
	cub3d->player_dir = vector_rotate(cub3d->init_pdir, cub3d->angle);
	cub3d->camera_plane = (t_vector){-cub3d->player_dir.y, cub3d->player_dir.x};
	cub3d->camera_plane = vector_multiply(cub3d->camera_plane, FOV_SCALE);
}

void	rotate_player(t_data *cub3d, int direction)
{
	cub3d->angle += (direction * ANGLE_STEP) + 360;
	cub3d->angle %= 360;
	cub3d->render = true;
	update_direction(cub3d);
}
