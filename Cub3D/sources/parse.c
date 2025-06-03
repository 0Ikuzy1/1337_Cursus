/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:40:20 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 23:54:29 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	validate_rgb(char **split)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (-1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (get_color(r, g, b));
}

int	parse_color(char *str)
{
	char	**split;
	int		color;
	int		i;

	while (*str && *str == ' ')
		str++;
	split = ft_split(str, ',');
	if (!split)
		return (-1);
	color = validate_rgb(split);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (color);
}

char	*parse_texture_path(char *line)
{
	char	*path;
	int		fd;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
	{
		return (NULL);
	}
	path = ft_strdup(line + i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		path = NULL;
	}
	else
	{
		close(fd);
	}
	return (path);
}

int	parse_and_validate_element(char *line, t_data *cub3d)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cub3d->map.no = parse_texture_path(line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cub3d->map.so = parse_texture_path(line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cub3d->map.we = parse_texture_path(line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cub3d->map.ea = parse_texture_path(line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		cub3d->map.f = parse_color(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		cub3d->map.c = parse_color(line + 2);
	else
		return (1);
	if ((ft_strncmp(line, "NO ", 3) == 0 && !cub3d->map.no) || (ft_strncmp(line,
				"SO ", 3) == 0 && !cub3d->map.so) || (ft_strncmp(line, "WE ",
				3) == 0 && !cub3d->map.we) || (ft_strncmp(line, "EA ", 3) == 0
			&& !cub3d->map.ea) || (ft_strncmp(line, "F ", 2) == 0
			&& cub3d->map.f == -1) || (ft_strncmp(line, "C ", 2) == 0
			&& cub3d->map.c == -1))
		return (-1);
	return (0);
}

int	process_element_line(char *line, t_data *cub3d)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (*line && *line == ' ')
		line++;
	if (line[0] == '\0')
		return (0);
	return (parse_and_validate_element(line, cub3d));
}
