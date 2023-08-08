/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/08 16:47:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "defines.h"

void	new_ray(t_ray *self, t_point3 origin, t_vec3 direction)
{
	self->direction = direction;
	self->origin = origin;
}

t_point3	ray_at(t_ray *r, float t)
{
	t_vec3	tmp;

	tmp = scale_vec3(t, &r->direction);
	return (sum_vec3(&r->origin, &tmp));
}
