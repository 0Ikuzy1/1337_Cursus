/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:41:56 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:07:25 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	initialize_ray(t_data *cub3d, int x, t_raycasting *ray_vars)
{
	double	camera_x;

	camera_x = 2 * x / (double)MAX_WIDTH - 1;
	ray_vars->ray_dir = vector_add(cub3d->player_dir,
			vector_multiply(cub3d->camera_plane, camera_x));
	ray_vars->curr_map_pos.x = (int)cub3d->player_pos.x;
	ray_vars->curr_map_pos.y = (int)cub3d->player_pos.y;
	if (ray_vars->ray_dir.x == 0)
		ray_vars->ray_step_size.x = 1e30;
	else
		ray_vars->ray_step_size.x = fabs(1 / ray_vars->ray_dir.x);
	if (ray_vars->ray_dir.y == 0)
		ray_vars->ray_step_size.y = 1e30;
	else
		ray_vars->ray_step_size.y = fabs(1 / ray_vars->ray_dir.y);
}

void	calculate_ray_steps(t_vector player_pos, t_raycasting *ray_vars)
{
	if (ray_vars->ray_dir.x < 0)
	{
		ray_vars->step.x = -1;
		ray_vars->ray_length_1d.x = (player_pos.x - ray_vars->curr_map_pos.x)
			* ray_vars->ray_step_size.x;
	}
	else
	{
		ray_vars->step.x = 1;
		ray_vars->ray_length_1d.x = ((ray_vars->curr_map_pos.x + 1)
				- player_pos.x) * ray_vars->ray_step_size.x;
	}
	if (ray_vars->ray_dir.y < 0)
	{
		ray_vars->step.y = -1;
		ray_vars->ray_length_1d.y = (player_pos.y - ray_vars->curr_map_pos.y)
			* ray_vars->ray_step_size.y;
	}
	else
	{
		ray_vars->step.y = 1;
		ray_vars->ray_length_1d.y = ((ray_vars->curr_map_pos.y + 1)
				- player_pos.y) * ray_vars->ray_step_size.y;
	}
}

void	perform_dda(t_data *cub3d, t_raycasting *ray_vars)
{
	bool	wall_hit;
	int		map_x;
	int		map_y;

	wall_hit = false;
	while (wall_hit == false)
	{
		if (ray_vars->ray_length_1d.x < ray_vars->ray_length_1d.y)
			step_x(ray_vars);
		else
			step_y(ray_vars);
		map_x = (int)ray_vars->curr_map_pos.x;
		map_y = (int)ray_vars->curr_map_pos.y;
		if (cub3d->map.map_arr[map_y][map_x] == 1)
			wall_hit = true;
	}
}

void	draw_wall_stripe(t_data *cub3d, int x, t_raycasting ray_vars)
{
	t_wall	wall_vars;

	wall_vars.line_height = (int)(MAX_HEIGHT / ray_vars.distance);
	wall_vars.draw_start = (MAX_HEIGHT / 2 - wall_vars.line_height / 2) - 1;
	if (wall_vars.draw_start < 0)
		wall_vars.draw_start = -1;
	wall_vars.draw_end = MAX_HEIGHT / 2 + wall_vars.line_height / 2;
	if (wall_vars.draw_end >= MAX_HEIGHT)
		wall_vars.draw_end = MAX_HEIGHT - 1;
	if (ray_vars.side == WEST || ray_vars.side == EAST)
		wall_vars.wall_x = cub3d->player_pos.y + ray_vars.distance
			* ray_vars.ray_dir.y;
	else
		wall_vars.wall_x = cub3d->player_pos.x + ray_vars.distance
			* ray_vars.ray_dir.x;
	wall_vars.wall_x -= floor(wall_vars.wall_x);
	wall_vars.tex_x = (int)(wall_vars.wall_x
			* cub3d->textures[ray_vars.side].width);
	wall_vars.step = 1.0 * cub3d->textures[ray_vars.side].height
		/ wall_vars.line_height;
	wall_vars.tex_pos = (wall_vars.draw_start - MAX_HEIGHT / 2
			+ wall_vars.line_height / 2) * wall_vars.step;
	paint_wall(cub3d, x, ray_vars, wall_vars);
}

void	raycasting(t_data *cub3d)
{
	int				x;
	t_raycasting	ray_vars;

	x = -1;
	while (++x < MAX_WIDTH)
	{
		initialize_ray(cub3d, x, &ray_vars);
		calculate_ray_steps(cub3d->player_pos, &ray_vars);
		perform_dda(cub3d, &ray_vars);
		draw_wall_stripe(cub3d, x, ray_vars);
	}
}
