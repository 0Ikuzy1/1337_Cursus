/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:42:32 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 22:55:43 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	load_texture(t_data *cub3d, t_texture *texture, char *path)
{
	texture->img.img_ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img.img_ptr)
		exit_cube(cub3d, 1, "Error\nFailed to load texture");
	texture->img.addr = mlx_get_data_addr(texture->img.img_ptr,
			&texture->img.bits_per_pixel, &texture->img.line_length,
			&texture->img.endian);
}

void	get_texture_pixel(t_texture *texture, int x, int y, int *color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < texture->width && y < texture->height)
	{
		dst = texture->img.addr + (y * texture->img.line_length + x
				* (texture->img.bits_per_pixel / 8));
		*color = *(unsigned int *)dst;
	}
}
