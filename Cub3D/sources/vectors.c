/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:43:38 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:10:16 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

t_vector	vector_multiply(t_vector vec, double scalar)
{
	t_vector	result;

	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return (result);
}

t_vector	vector_add(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	return (vector);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (PI / 180.0f));
}

t_vector	vector_rotate(t_vector vec, double angle)
{
	double		radiant;
	t_vector	result;

	radiant = degrees_to_radians(angle);
	result.x = vec.x * cos(radiant) - vec.y * sin(radiant);
	result.y = vec.x * sin(radiant) + vec.y * cos(radiant);
	return (result);
}
