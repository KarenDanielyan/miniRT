/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 01:00:26 by kdaniely         ###   ########.fr       */
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

bool	hit_plane(t_shape *self, t_ray *r, double *t)
{
	t_plane		*pl;
	t_vec3		tmp;
	double		denom;
	double		numer;

	pl = &self->p;
	denom = vec3_dot(&pl->normal, &r->direction);
	if (fabs(denom) < 0.0001)
		return (false);
	tmp = subst_vec3(&pl->center, &r->origin);
	numer = vec3_dot(&pl->normal, &tmp);
	*t = -numer / denom;
	if (*t < 0.0001)
		return (false);
	return (true);
}

/**
 * @brief	hit_cylinder() checks if a ray r hits a cylinder self.
 * 
 * @param self		Pointer to the cylinder.
 * @param r			Pointer to the ray.
 * @param t			Reference to the distance to the hit point.
 * @return true		If the ray hits the cylinder.
 * @return false	If the ray does not hit the cylinder.
 */
bool	hit_cylinder(t_shape *self, t_ray *r, double *t)
{
	(void)self;
	(void)r;
	(void)t;
	return (false);
}
