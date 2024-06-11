/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:20:48 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/11 15:49:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"
#include "matrix.h"

bool	hit_cone_walls(t_cone *cn, t_ray *r, double *t)
{
	t_tuple4f	q;
	t_point3	p;
	t_vec3		co;

	co = subst_vec3(&r->origin, &cn->apex);
	q.i = pow(vec3_dot(&r->direction, &cn->normal), 2) - pow(cos(cn->angle), 2);
	q.j = 2 * (vec3_dot(&r->direction, &cn->normal) \
			* vec3_dot(&co, &cn->normal) \
			- vec3_dot(&r->direction, &co) * pow(cos(cn->angle), 2));
	q.k = pow(vec3_dot(&co, &cn->normal), 2) - vec3_dot(&co, &co) \
		* pow(cos(cn->angle), 2);
	q.w = q.j * q.j - 4 * q.i * q.k;
	if (q.w < 0.0)
		return (false);
	*t = (-q.j + sqrt(q.w)) / (2 * q.i);
	p = ray_at(r, *t);
	if (*t < EPSILON || get_z(&p) > EPSILON || get_z(&p) < -(cn->height))
		*t = (-q.j - sqrt(q.w)) / (2 * q.i);
	p = ray_at(r, *t);
	if (*t < EPSILON || get_z(&p) > EPSILON || get_z(&p) < -(cn->height))
		return (false);
	return (true);
}

bool	hit_cone_cap(t_cone *cn, t_ray *r, double *t)
{
	t_shape		pl;
	t_point3	p;
	t_vec3		co;

	pl.pl.center = scale_vec3(cn->height, &cn->normal);
	pl.pl.center = sum_vec3(&cn->apex, &pl.pl.center);
	pl.pl.normal = cn->normal;
	if (hit_plane(&pl, r, t))
	{
		p = ray_at(r, *t);
		co = subst_vec3(&p, &pl.pl.center);
		if (*t < EPSILON || vec3_length(&co) > cn->radius)
			return (false);
		return (true);
	}
	return (false);
}

/* Ray cone intersection function */
bool	hit_cone(t_shape *self, t_ray *r, double *t)
{
	t_cone	cn_prime;
	t_ray	r_prime;
	double	t_prime[2];

	cn_prime = self->cn;
	r_prime.origin = apply_transform_to_point(&self->cn.wtl_matrix, &r->origin);
	r_prime.direction = \
		apply_transform_to_vector(&self->cn.wtl_matrix, &r->direction);
	cn_prime.apex = vec3(0, 0, 0);
	cn_prime.normal = vec3(0, 0, -1);
	if (hit_cone_walls(&cn_prime, &r_prime, &t_prime[0]))
	{
		if (hit_cone_cap(&cn_prime, &r_prime, &t_prime[1]))
		{
			if (t_prime[0] < t_prime[1])
				*t = t_prime[0];
			else
				*t = t_prime[1];
			return (true);
		}
		*t = t_prime[0];
		return (true);
	}
	return (hit_cone_cap(&cn_prime, &r_prime, t));
}
