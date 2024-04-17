/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 16:35:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

/*
 * NOTE:	Highly likely we can switch dot product in a to 1,
 * 			as direction is a unit vector anyways.
*/
float	hit_sphere(t_sphere *self, t_ray *r)
{
	t_tuple4f			q;
	t_vec3				o;

	o = subst_vec3(&self->center, &r->origin);
	q.i = vec3_length_squared(&r->direction);
	q.j = vec3_dot(&r->direction, &o);
	q.k = vec3_length_squared(&o) - (self->radius * self->radius);
	q.w = q.j * q.j - q.i * q.k;
	if (q.w < 0.0)
		return (-1.0);
	return ((q.j - sqrt(q.w)) / q.i);
}

float	sphere_hit(t_point3 center, float radius, t_ray *r)
{
	t_tuple4f	q;
	t_vec3		o;

	o = subst_vec3(&center, &r->origin);
	q.i = vec3_length_squared(&r->direction);
	q.j = vec3_dot(&r->direction, &o);
	q.k = vec3_length_squared(&o) - (radius * radius);
	q.w = q.j * q.j - q.i * q.k;
	if (q.w < 0.0)
		return (-1.0);
	return ((q.j - sqrt(q.w)) / q.i);
}
