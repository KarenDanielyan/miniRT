/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 16:57:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "defines.h"

void	new_ray(t_ray *self, t_point3 origin, t_vec3 direction)
{
	self->direction = direction;
	self->origin = origin;
}

void	ray_new(t_ray *self, t_point3 from, t_point3 to)
{
	t_vec3	dir;

	dir = subst_vec3(&to, &from);
	vec3_normalize(&dir);
	self->origin = from;
	self->direction = dir;
}

t_point3	ray_at(t_ray *r, float t)
{
	t_vec3	tmp;

	tmp = scale_vec3(t, &r->direction);
	return (sum_vec3(&r->origin, &tmp));
}
