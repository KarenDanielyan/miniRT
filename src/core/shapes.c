/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:52:33 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/19 21:00:51 by armhakob         ###   ########.fr       */
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
	return (NULL);
}
