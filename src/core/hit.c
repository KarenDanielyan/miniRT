/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 02:50:13 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

struct s_quadratic
{
	float	a;
	float	b;
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
	q.a = vec3_dot(&r->direction, &r->direction);
	q.b = -2 * vec3_dot(&r->direction, &o);
	q.c = vec3_dot(&o, &o) - (self->radius * self->radius);
	q._d = q.b * q.b - 4 * q.a * q.c;
	if (q._d < 0.0)
		return (-1.0);
	return (1.0);
}

float	sphere_hit(t_point3 center, float radius, t_ray *r)
{
	struct s_quadratic	q;
	t_vec3				o;
	float				t[2];

	o = subst_vec3(&center, &r->origin);
	q.a = vec3_dot(&r->direction, &r->direction);
	q.b = -2 * vec3_dot(&r->direction, &o);
	q.c = vec3_dot(&o, &o) - (radius * radius);
	q._d = q.b * q.b - 4 * q.a * q.c;
	if (q._d >= 0)
	{
		t[0] = (-q.b + sqrt(q._d)) / (2 * q.a);
		t[1] = (-q.b - sqrt(q._d)) / (2 * q.a);
		if (t[0] > 0.0 || t[1] > 0.0)
			return (t[1]);
	}
	return (-1.0);
}
