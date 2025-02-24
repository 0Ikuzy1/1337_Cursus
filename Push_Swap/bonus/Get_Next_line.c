/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:37:39 by ozouine           #+#    #+#             */
/*   Updated: 2024/05/06 09:24:12 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*buffer_reader(char *str, int fd)
{
	ssize_t	read_bytes;
	char	*buffer;
	char	*tmp;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = 0;
	}
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(str), NULL);
		buffer[read_bytes] = '\0';
		tmp = str;
		str = ft_strjoin1(str, buffer);
		free(tmp);
	}
	return (free(buffer), str);
}

char	*readline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*line_remover(char *str)
{
	int		i;
	int		j;
	char	*holder;

	if (!*str)
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	holder = malloc(ft_strlen(str) - i + 1);
	if (!holder)
		return (free(str), NULL);
	j = 0;
	while (str[i])
	{
		holder[j] = str[i];
		i++;
		j++;
	}
	holder[j] = '\0';
	return (free(str), holder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = buffer_reader(str, fd);
	if (!str)
		return (NULL);
	line = readline(str);
	str = line_remover(str);
	if (!str)
		return (free(line), NULL);
	return (line);
}
