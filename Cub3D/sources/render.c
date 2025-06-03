/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:44:13 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:02:33 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	get_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	plant_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= MAX_HEIGHT)
		return (1);
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
	return (0);
}

t_line	init_line_params(t_vector start, t_vector end)
{
	t_line	line;

	line.x = start.x;
	line.y = start.y;
	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_increment = line.dx / (float)line.steps;
	line.y_increment = line.dy / (float)line.steps;
	return (line);
}

void	draw_line(t_data *cub3d, t_vector start, t_vector end, int color)
{
	t_line	line;
	int		i;

	line = init_line_params(start, end);
	i = 0;
	while (i <= line.steps)
	{
		plant_pixel(&cub3d->image, (int)round(line.x), (int)round(line.y),
			color);
		line.x += line.x_increment;
		line.y += line.y_increment;
		i++;
	}
}

void	reset_screen(t_data *cub3d)
{
	ft_bzero(cub3d->image.addr, MAX_WIDTH * (cub3d->image.bits_per_pixel / 8)
		* MAX_HEIGHT);
}
