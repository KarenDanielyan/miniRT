/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:47:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 18:07:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "shapes.h"

/* In this file we save hit function we implemented for debugging. */

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
	return ((q.j - sqrtf(q.w)) / q.i);
}
