/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:39:23 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 22:39:40 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	get_map_dimensions(char **map, int *rows, int *cols)
{
	int	i;
	int	max_cols;
	int	line_len;

	i = 0;
	max_cols = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len > 0 && map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len > max_cols)
			max_cols = line_len;
		i++;
	}
	*rows = i;
	*cols = max_cols;
}

int	is_map_element(char *line)
{
	while (*line && *line == ' ')
		line++;
	if (*line == '\0')
		return (0);
	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0
		&& ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0)
		return (1);
	return (0);
}

int	count_map_lines(int fd, int *map_line_count)
{
	char	*line;
	int		in_map;

	*map_line_count = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!in_map && line[0] != '\0')
		{
			if (is_map_element(line))
			{
				in_map = 1;
				(*map_line_count)++;
			}
		}
		else if (in_map)
			(*map_line_count)++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	read_map_line(char *line, int *in_map, char **map_lines, t_data *cub3d)
{
	int			result;
	static int	i = 0;

	if (!(*in_map))
	{
		result = process_element_line(line, cub3d);
		if (result == 1 && line[0] != '\0')
		{
			*in_map = 1;
			map_lines[i++] = ft_strdup(line);
		}
		else if (result == -1)
			return (-1);
	}
	else
		map_lines[i++] = ft_strdup(line);
	return (i);
}

int	read_map_elements(int fd, char **map_lines, t_data *cub3d)
{
	char	*line;
	int		in_map;
	int		i;

	in_map = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = read_map_line(line, &in_map, map_lines, cub3d);
		if (i == -1)
		{
			free(line);
			free(map_lines);
			exit_cube(cub3d, 1, "Error\nInvalid element");
		}
		free(line);
		line = get_next_line(fd);
	}
	map_lines[i] = NULL;
	return (0);
}
