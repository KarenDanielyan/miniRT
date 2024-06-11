/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:16:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/11 20:55:19 by kdaniely         ###   ########.fr       */
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

/*
	vec3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
	vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
	return r_out_perp + r_out_parallel;
*/
t_vec3	ray_refract(t_vec3 *v, t_vec3 *n, double ni_over_nt)
{
	double	cos_theta;
	t_vec3	minus_v;
	t_vec3	perp;
	t_vec3	parallel;

	vec3_normalize(v);
	minus_v = vec3_neg(v);
	cos_theta = vec3_dot(&minus_v, n);
	perp = scale_vec3(cos_theta, n);
	perp = sum_vec3(v, &perp);
	perp = scale_vec3(ni_over_nt, &perp);
	parallel = scale_vec3(-sqrt(fabs(1.0 - vec3_length_squared(&perp))), n);
	return (sum_vec3(&perp, &parallel));
}
