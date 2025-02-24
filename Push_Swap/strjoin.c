/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:41:29 by ozouine           #+#    #+#             */
/*   Updated: 2024/04/29 21:21:14 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dest_len;
	size_t	total_len;
	size_t	i;

	dest_len = 0;
	i = 0;
	if (!dst && size == 0)
		return (0);
	while (dst[dest_len] && dest_len <= size)
		dest_len++;
	if (dest_len >= size)
		return (size + ft_strlen(src));
	total_len = dest_len + ft_strlen(src);
	while (src[i] && dest_len < size - 1)
		dst[dest_len++] = src[i++];
	dst[dest_len] = '\0';
	return (total_len);
}

static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s);
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2) + 2;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, " ", ft_strlen(s1) + 2);
	ft_strlcat(result, s2, i);
	return (result);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	i;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, i);
	return (result);
}
