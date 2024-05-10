/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 17:45:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

/*
 * NOTE:	Highly likely we can switch dot product in a to 1,
 * 			as direction is a unit vector anyways.
*/
bool	hit_sphere(t_shape *self, t_ray *r, double *t)
{
	t_sphere	*sp;
	t_tuple4f	q;
	t_vec3		o;

	sp = &self->s;
	o = subst_vec3(&sp->center, &r->origin);
	q.i = vec3_length_squared(&r->direction);
	q.j = vec3_dot(&r->direction, &o);
	q.k = vec3_length_squared(&o) - (sp->radius * sp->radius);
	q.w = q.j * q.j - q.i * q.k;
	if (q.w < 0.0)
		return (false);
	*t = (q.j - sqrt(q.w)) / q.i;
	if (*t < 0.0001)
		*t = (q.j + sqrt(q.w)) / q.i;
	if (*t < 0.0001)
		return (false);
	return (true);
}
