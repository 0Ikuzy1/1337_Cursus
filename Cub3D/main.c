/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:35:56 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 23:14:25 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/cub3d.h"

void	roof_n_floor(t_image *img, int roof_color, int floor_color)
{
	int	i;
	int	y;

	y = 0;
	while (y < MAX_HEIGHT / 2)
	{
		i = 0;
		while (i < MAX_WIDTH)
		{
			plant_pixel(img, i, y, roof_color);
			i++;
		}
		y++;
	}
	y = MAX_HEIGHT / 2;
	while (y < MAX_HEIGHT)
	{
		i = 0;
		while (i < MAX_WIDTH)
		{
			plant_pixel(img, i, y, floor_color);
			i++;
		}
		y++;
	}
}

int	render(t_data *cub3d)
{
	if (!cub3d->win)
		return (1);
	if (cub3d->render)
	{
		reset_screen(cub3d);
		roof_n_floor(&cub3d->image, cub3d->map.c, cub3d->map.f);
		raycasting(cub3d);
		mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->image.img_ptr, 0,
			0);
		cub3d->render = false;
	}
	return (0);
}

void	cube_init(t_data *cub3d)
{
	cub3d->render = true;
	update_direction(cub3d);
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, MAX_WIDTH, MAX_HEIGHT, "CUB3D");
	cub3d->image.img_ptr = mlx_new_image(cub3d->mlx, MAX_WIDTH, MAX_HEIGHT);
	cub3d->image.addr = mlx_get_data_addr(cub3d->image.img_ptr,
			&cub3d->image.bits_per_pixel, &cub3d->image.line_length,
			&cub3d->image.endian);
	load_texture(cub3d, &cub3d->textures[0], cub3d->map.no);
	load_texture(cub3d, &cub3d->textures[1], cub3d->map.so);
	load_texture(cub3d, &cub3d->textures[2], cub3d->map.we);
	load_texture(cub3d, &cub3d->textures[3], cub3d->map.ea);
}

int	main(int argc, char **argv)
{
	t_data	cub3d;

	ft_bzero(&cub3d, sizeof(t_data));
	if (argc != 2)
	{
		printf("Error\nUsage: ./cub3d <map.cub>\n");
		return (1);
	}
	if (!argv[1] || ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1]
			+ ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		printf("Error\nInvalid file extension\n");
		return (1);
	}
	cub3d.map.c = -1;
	cub3d.map.f = -1;
	parse_map(&cub3d, argv[1]);
	cube_init(&cub3d);
	mlx_hook(cub3d.win, KeyPress, KeyPressMask, &handle_events, &cub3d);
	mlx_hook(cub3d.win, 17, 0, &close_window, &cub3d);
	mlx_loop_hook(cub3d.mlx, &render, &cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
