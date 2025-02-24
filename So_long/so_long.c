/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:26:52 by ozouine           #+#    #+#             */
/*   Updated: 2024/07/30 15:19:06 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	destroy(t_mlx *lbx)
{
	mlx_destroy_image(lbx->mlx, lbx->ground);
	mlx_destroy_image(lbx->mlx, lbx->player);
	mlx_destroy_image(lbx->mlx, lbx->wall);
	mlx_destroy_image(lbx->mlx, lbx->coll);
	mlx_destroy_image(lbx->mlx, lbx->exit);
	mlx_clear_window(lbx->mlx, lbx->mlx_win);
	mlx_destroy_window(lbx->mlx, lbx->mlx_win);
	mlx_destroy_display(lbx->mlx);
	ft_free(lbx->map);
	lbx->map = NULL;
	ft_free(lbx->map_dup);
	lbx->map_dup = NULL;
	free(lbx->mlx);
}

void	main_helper(t_mlx *lbx, int i, char *join, t_var *v)
{
	lbx->map = ft_split(join, '\n');
	lbx->map_dup = ft_split(join, '\n');
	if (join == NULL)
		closenkill(lbx, "empty Map File", 1, v);
	line_len(lbx, lbx->map, i, v);
	check_borders(lbx, lbx->map, i, v);
	check_comp(lbx, lbx->map, i, v);
	count_comp(lbx, lbx->map, i, v);
	free(join);
	join = NULL;
}

void	innit(t_mlx *lbx, t_var *v, char *str)
{
	v->i = 0;
	v->join = NULL;
	v->fd = open(str, O_RDONLY);
	v->get_line = get_next_line(v->fd);
	lbx->count_mv = 0;
	lbx->map = NULL;
	while (v->get_line != NULL)
	{
		v->free_j = v->join;
		v->free_l = v->get_line;
		v->join = ft_strjoin(v->join, v->get_line);
		v->get_line = get_next_line(v->fd);
		free(v->free_l);
		free(v->free_j);
		v->i++;
	}
	close(v->fd);
}

int	main(int ac, char **av)
{
	t_mlx	lbx;
	t_var	v;

	if (ac == 2)
	{
		innit(&lbx, &v, av[1]);
		main_helper(&lbx, v.i, v.join, &v);
		lbx.i = v.i;
		lbx.j = ft_strlen(lbx.map[0]);
		count_colls(&lbx);
		ft_validate_path(&lbx, &v);
		lbx.mlx = mlx_init();
		if (lbx.mlx == NULL)
			return (1);
		if ((v.i * 30) > 1080 || (ft_strlen(lbx.map[0]) * 30) > 1920)
			closenkill(&lbx, "Map is Too Big\n", 1, &v);
		lbx.mlx_win = mlx_new_window(lbx.mlx, ft_strlen(lbx.map[0]) * 30, v.i
				* 30, "So_long");
		convert_img(&lbx, &v);
		draw_map(&lbx, 0, 0);
		mlx_hook(lbx.mlx_win, 17, 0, ft_exit, &lbx);
		mlx_key_hook(lbx.mlx_win, move_keys, &lbx);
		mlx_loop(lbx.mlx);
	}
}
