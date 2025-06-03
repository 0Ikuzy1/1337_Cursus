/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:37:47 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 22:37:59 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	close_window(t_data *cub3d)
{
	exit_cube(cub3d, 0, "Window closed.");
	return (0);
}

void	exit_cube(t_data *cub3d, int exit_code, char *exit_message)
{
	int	i;

	i = 0;
	printf("%s\n", exit_message);
	while (i < 4)
	{
		if (cub3d->textures[i].img.img_ptr)
			mlx_destroy_image(cub3d->mlx, cub3d->textures[i].img.img_ptr);
		i++;
	}
	if (cub3d->image.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->image.img_ptr);
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->mlx)
		mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	exit(exit_code);
}

int	handle_events(int keysym, t_data *cub3d)
{
	if (keysym == XK_Escape)
		close_window(cub3d);
	else if (keysym == XK_a || keysym == XK_d || keysym == XK_w
		|| keysym == XK_s)
		player_movement(cub3d, keysym);
	else if (keysym == XK_Left)
		rotate_player(cub3d, -1);
	else if (keysym == XK_Right)
		rotate_player(cub3d, 1);
	cub3d->render = true;
	return (0);
}
