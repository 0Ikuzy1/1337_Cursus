/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:24 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/03 22:38:42 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	free_clean_map(char **clean_map, int rows)
{
	int	k;

	k = 0;
	while (k < rows)
	{
		free(clean_map[k]);
		k++;
	}
	free(clean_map);
}

char	**create_clean_map(char **map, int rows)
{
	char	**clean_map;
	int		i;
	int		len;

	clean_map = malloc(sizeof(char *) * (rows + 1));
	if (!clean_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		clean_map[i] = ft_strdup(map[i]);
		if (!clean_map[i])
		{
			free_clean_map(clean_map, i);
			return (NULL);
		}
		len = ft_strlen(clean_map[i]);
		if (len > 0 && clean_map[i][len - 1] == '\n')
			clean_map[i][len - 1] = '\0';
		i++;
	}
	clean_map[rows] = NULL;
	return (clean_map);
}

int	fill_int_map(t_data *cub3d, char **charMap, int i)
{
	int		j;
	char	*line;

	line = charMap[i];
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	j = 0;
	while (j < cub3d->map.cols)
	{
		if (j >= (int)ft_strlen(line) || line[j] == ' ' || line[j] == '1')
			cub3d->map.map_arr[i][j] = 1;
		else if (line[j] == '0')
			cub3d->map.map_arr[i][j] = 0;
		else if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E'
			|| line[j] == 'W')
		{
			cub3d->map.map_arr[i][j] = 0;
			cub3d->player_pos.x = j + 0.5;
			cub3d->player_pos.y = i + 0.5;
			set_player_direction(cub3d, line[j]);
		}
		j++;
	}
	return (0);
}

void	set_player_direction(t_data *cub3d, char dir)
{
	if (dir == 'N')
		cub3d->init_pdir = (t_vector){0, -1};
	else if (dir == 'S')
		cub3d->init_pdir = (t_vector){0, 1};
	else if (dir == 'E')
		cub3d->init_pdir = (t_vector){1, 0};
	else if (dir == 'W')
		cub3d->init_pdir = (t_vector){-1, 0};
}

int	create_int_map(t_data *cub3d, char **charMap)
{
	int	i;

	cub3d->map.map_arr = malloc(sizeof(int *) * cub3d->map.rows);
	if (!cub3d->map.map_arr)
		return (-1);
	i = 0;
	while (i < cub3d->map.rows)
	{
		cub3d->map.map_arr[i] = malloc(sizeof(int) * cub3d->map.cols);
		if (!cub3d->map.map_arr[i])
			return (-1);
		fill_int_map(cub3d, charMap, i);
		i++;
	}
	return (0);
}
