/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:39:51 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:07:08 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	flood_fill(char **map, int max_rows, int row, int col)
{
	if (row < 0 || col < 0 || row >= max_rows
		|| col >= (int)ft_strlen(map[row]))
	{
		return (-1);
	}
	if (map[row][col] == '1' || map[row][col] == 'X')
		return (0);
	if (map[row][col] == ' ')
	{
		return (-1);
	}
	map[row][col] = 'X';
	if (flood_fill(map, max_rows, row - 1, col) == -1 || flood_fill(map,
			max_rows, row + 1, col) == -1 || flood_fill(map, max_rows, row, col
			- 1) == -1 || flood_fill(map, max_rows, row, col + 1) == -1)
		return (-1);
	return (0);
}

int	validate_map_flood_fill(char **clean_map, int rows, int player_pos[2])
{
	int	result;

	if (player_pos[0] < 0 || player_pos[1] < 0)
		return (-1);
	clean_map[player_pos[1]][player_pos[0]] = '0';
	result = flood_fill(clean_map, rows, player_pos[1], player_pos[0]);
	return (result);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	check_map_characters(char **map, int rows, int player_pos[2])
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player_count++;
				player_pos[0] = j;
				player_pos[1] = i;
			}
			if (!is_valid_map_char(map[i][j]))
				return (-1);
		}
	}
	if (player_count == 1)
		return (0);
	return (-1);
}

int	validate_map(char **map, int rows, int cols)
{
	char	**clean_map;
	int		player_pos[2];
	int		result;

	player_pos[0] = -1;
	player_pos[1] = -1;
	if (rows < 3 || cols < 3)
		return (-1);
	clean_map = create_clean_map(map, rows);
	if (!clean_map)
		return (-1);
	if (check_map_characters(clean_map, rows, player_pos) < 0)
	{
		free_clean_map(clean_map, rows);
		return (-1);
	}
	if (player_pos[0] < 0 || player_pos[1] < 0)
		result = -1;
	else
	{
		clean_map[player_pos[1]][player_pos[0]] = '0';
		result = flood_fill(clean_map, rows, player_pos[1], player_pos[0]);
	}
	free_clean_map(clean_map, rows);
	return (result);
}
