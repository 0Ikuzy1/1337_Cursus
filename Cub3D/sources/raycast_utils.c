/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:41:30 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:09:47 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	step_x(t_raycasting *ray_vars)
{
	ray_vars->curr_map_pos.x += ray_vars->step.x;
	ray_vars->distance = ray_vars->ray_length_1d.x;
	ray_vars->ray_length_1d.x += ray_vars->ray_step_size.x;
	if (ray_vars->step.x > 0)
		ray_vars->side = EAST;
	else
		ray_vars->side = WEST;
}

void	step_y(t_raycasting *ray_vars)
{
	ray_vars->curr_map_pos.y += ray_vars->step.y;
	ray_vars->distance = ray_vars->ray_length_1d.y;
	ray_vars->ray_length_1d.y += ray_vars->ray_step_size.y;
	if (ray_vars->step.y > 0)
		ray_vars->side = SOUTH;
	else
		ray_vars->side = NORTH;
}

void	paint_wall(t_data *cub3d, int x, t_raycasting ray_vars,
		t_wall wall_vars)
{
	while (++wall_vars.draw_start < wall_vars.draw_end)
	{
		wall_vars.tex_y = (int)wall_vars.tex_pos
			& (cub3d->textures[ray_vars.side].height - 1);
		wall_vars.tex_pos += wall_vars.step;
		get_texture_pixel(&cub3d->textures[ray_vars.side], wall_vars.tex_x,
			wall_vars.tex_y, &wall_vars.color);
		plant_pixel(&cub3d->image, x, wall_vars.draw_start, wall_vars.color);
	}
}
