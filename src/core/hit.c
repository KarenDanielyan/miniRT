/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 03:14:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

/*
 * TODO: Add comment explaining the difference between
 * standard quadratic coefficients and ones we use here.
*/

struct s_quadratic
{
	float	a;
	float	h;
	float	c;
	float	_d;
};

/*
 * NOTE:	Highly likely we can switch dot product in a to 1,
 * 			as direction is a unit vector anyways.
*/
float	hit_sphere(t_sphere *self, t_ray *r)
{
	struct s_quadratic	q;
	t_vec3				o;

	o = subst_vec3(&self->center, &r->origin);
	q.a = vec3_length_squared(&r->direction);
	q.h = vec3_dot(&r->direction, &o);
	q.c = vec3_length_squared(&o) - (self->radius * self->radius);
	q._d = q.h * q.h - q.a * q.c;
	if (q._d < 0.0)
		return (-1.0);
	return ((q.h - sqrt(q._d)) / q.a);
}

float	sphere_hit(t_point3 center, float radius, t_ray *r)
{
	struct s_quadratic	q;
	t_vec3				o;

	o = subst_vec3(&center, &r->origin);
	q.a = vec3_length_squared(&r->direction);
	q.h = vec3_dot(&r->direction, &o);
	q.c = vec3_length_squared(&o) - (radius * radius);
	q._d = q.h * q.h - q.a * q.c;
	if (q._d < 0.0)
		return (-1.0);
	return ((q.h - sqrt(q._d)) / q.a);
}
