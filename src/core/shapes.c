/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:52:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 19:50:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

void	*new_sphere(t_point3 center, float radius)
{
	t_sphere	*sp;

	sp = ft_calloc(1, sizeof(t_sphere));
	if (sp == NULL)
	{
		perror("new_sphere: ");
		exit(EXIT_FAILURE);
	}
	sp->center = center;
	sp->radius = radius;
	sp->wtl_matrix = world_to_local(&center, NULL);
	return (sp);
}

void	*new_plane(t_point3 center, t_vec3 normal)
{
	t_plane	*pl;

	pl = ft_calloc(1, sizeof(t_plane));
	if (pl == NULL)
	{
		perror("new_plane: ");
		exit(EXIT_FAILURE);
	}
	pl->center = center;
	pl->normal = normal;
	pl->wtl_matrix = world_to_local(&center, &normal);
	return (pl);
}

void	*new_cylinder(t_point3 center, t_vec3 normal, \
	float radius, float height)
{
	t_cylinder	*cy;

	cy = ft_calloc(1, sizeof(t_cylinder));
	if (cy == NULL)
	{
		perror("new_cylinder: ");
		exit(EXIT_FAILURE);
	}
	cy->center = center;
	cy->normal = normal;
	cy->radius = radius;
	cy->height = height;
	cy->wtl_matrix = world_to_local(&center, &normal);
	return (cy);
}

void	*new_cone(t_point3 center, t_vec3 normal, \
	float radius, float height)
{
	t_cone	*cn;

	cn = ft_calloc(1, sizeof(t_cone));
	if (cn == NULL)
	{
		perror("new_cone: ");
		exit(EXIT_FAILURE);
	}
	cn->center = center;
	cn->normal = normal;
	cn->radius = radius;
	cn->height = height;
	cn->angle = atan(radius / height);
	cn->apex = scale_vec3(height / 2, &normal);
	cn->apex = sum_vec3(&center, &cn->apex);
	cn->wtl_matrix = world_to_local(&center, &normal);
	return (cn);
}
