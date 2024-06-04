/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/04 15:31:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "defines.h"

void	new_ray(t_ray *self, t_point3 origin, t_vec3 direction)
{
	self->direction = direction;
	vec3_normalize(&self->direction);
	self->origin = origin;
}

void	new_ray_from_to(t_ray *self, t_point3 from, t_point3 to)
{
	t_vec3	dir;

	dir = subst_vec3(&to, &from);
	vec3_normalize(&dir);
	self->origin = from;
	self->direction = dir;
}

t_point3	ray_at(t_ray *r, double t)
{
	t_vec3	tmp;

	tmp = scale_vec3(t, &r->direction);
	return (sum_vec3(&r->origin, &tmp));
}

t_vec3	ray_reflect(t_vec3 *v, t_vec3 *n)
{
	t_vec3	tmp;

	tmp = scale_vec3(2 * vec3_dot(v, n), n);
	tmp = subst_vec3(v, &tmp);
	return (tmp);
}
