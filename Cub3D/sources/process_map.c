/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:54 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 23:54:46 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

char	**allocate_map_lines(int map_line_count, t_data *cub3d)
{
	char	**map_lines;

	map_lines = malloc(sizeof(char *) * (map_line_count + 1));
	if (!map_lines)
		exit_cube(cub3d, 1, "Error\nMemory allocation failed");
	return (map_lines);
}

int	validate_required_elements(t_data *cub3d, char **map_lines)
{
	int	i;

	if (!cub3d->map.no || !cub3d->map.so || !cub3d->map.we || !cub3d->map.ea
		|| cub3d->map.c == -1 || cub3d->map.f == -1)
	{
		i = 0;
		while (map_lines[i])
			free(map_lines[i++]);
		free(map_lines);
		exit_cube(cub3d, 1, "Error\nMissing texture or color");
	}
	return (0);
}

int	process_map_data(t_data *cub3d, char **map_lines)
{
	int	i;

	get_map_dimensions(map_lines, &cub3d->map.rows, &cub3d->map.cols);
	if (validate_map(map_lines, cub3d->map.rows, cub3d->map.cols) == -1
		|| create_int_map(cub3d, map_lines) == -1)
	{
		i = 0;
		while (map_lines[i])
			free(map_lines[i++]);
		free(map_lines);
		exit_cube(cub3d, 1, "Error\nInvalid map");
	}
	return (0);
}

void	cleanup_map_lines(char **map_lines)
{
	int	i;

	i = 0;
	while (map_lines[i])
		free(map_lines[i++]);
	free(map_lines);
}

int	parse_map(t_data *cub3d, char *file_path)
{
	int		fd;
	char	**map_lines;
	int		map_line_count;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit_cube(cub3d, 1, "Error\nFailed to open map file");
	count_map_lines(fd, &map_line_count);
	close(fd);
	map_lines = allocate_map_lines(map_line_count, cub3d);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		free(map_lines);
		exit_cube(cub3d, 1, "Error\nFailed to open map file");
	}
	read_map_elements(fd, map_lines, cub3d);
	close(fd);
	validate_required_elements(cub3d, map_lines);
	process_map_data(cub3d, map_lines);
	cleanup_map_lines(map_lines);
	return (0);
}
