/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:55 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 18:42:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"
#include "quaternion.h"

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
	if (*t < EPSILON)
		*t = (q.j + sqrt(q.w)) / q.i;
	if (*t < EPSILON)
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
	if (fabs(denom) < EPSILON)
		return (false);
	tmp = subst_vec3(&pl->center, &r->origin);
	numer = vec3_dot(&pl->normal, &tmp);
	*t = -numer / denom;
	if (*t < EPSILON)
		return (false);
	return (true);
}

bool	hit_cylinder_walls(t_cylinder *cy, t_ray *r, double *t);
bool	hit_cylinder_caps(t_cylinder *cy, t_ray *r, double *t);

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
	t_cylinder		cy_prime;
	t_ray			r_prime;
	t_quaternion	q;
	double			t_prime[2];

	cy_prime.normal = vec3(0, 0, 1);
	cy_prime.center = vec3(0, 0, 0);
	q = get_quaternion(&self->c.normal, &cy_prime.normal);
	r_prime.origin = subst_vec3(&r->origin, &cy_prime.center);
	r_prime.origin = quarternion_rotate(&q, &r->origin);
	r_prime.direction = quarternion_rotate(&q, &r->direction);
	if (hit_cylinder_walls(&cy_prime, &r_prime, &t_prime[0]) || \
		hit_cylinder_caps(&cy_prime, &r_prime, &t_prime[1]))
	{
		if (t_prime[0] < t_prime[1] && t_prime[0] > EPSILON)
			*t = t_prime[0];
		else if (t_prime[1] > EPSILON)
			*t = t_prime[1];
	}
	if (*t > EPSILON)
		return (true);
	return (false);
}

/**
 * @brief 			hit_cylinder_walls() checks if a ray r 
 * 					hits the walls of a cylinder cy.
 * 
 * @param cy 		Pointer to the cylinder.
 * @param r 		Pointer to the ray.
 * @param t 		Reference to the distance to the hit point.
 * @return true 	If the ray hits the cylinder.
 * @return false 	If the ray does not hit the cylinder.
 * 
 * @details	We use b = -2h and q.j = h to simplify the equation.
 * 			Using this quadratic will take this form:
 * 				q.i * t^2 - 2 * q.j *t + q.k = 0,
 * 			Where (assuming r->d = [x, y] && r->o = [x0, y0]):
 * 				1. q.i = (x^2 + y^2),
 * 				2. q.j = 2 * (x * x0 + y * y0)
 * 				3. q.k = x0^2 + y0^2 - r^2
 */
bool	hit_cylinder_walls(t_cylinder *cy, t_ray *r, double *t)
{
	t_tuple4f	q;
	t_point3	p;

	*t = -1;
	q.i = (pow(get_x(&r->direction), 2)) + (pow(get_y(&r->direction), 2));
	q.j = -((get_x(&r->direction) * get_x(&r->origin) \
			+ get_y(&r->direction) * get_y(&r->origin)));
	q.k = pow(get_x(&r->origin), 2) + pow(get_y(&r->origin), 2) \
		- pow(cy->radius, 2);
	q.w = q.j * q.j - q.i * q.k;
	if (q.w < EPSILON)
		return (false);
	*t = (q.j - sqrt(q.w)) / q.i;
	p = ray_at(r, *t);
	if (*t < EPSILON || get_z(&p) < (get_z(&cy->center) - cy->height / 2) || \
		get_z(&p) > (get_z(&cy->center) + cy->height / 2))
		*t = (q.j + sqrt(q.w)) / q.i;
	if (*t < EPSILON || get_z(&p) < (get_z(&cy->center) - cy->height / 2) || \
		get_z(&p) > (get_z(&cy->center) + cy->height / 2))
		return (false);
	return (true);
}

bool	hit_cylinder_caps(t_cylinder *cy, t_ray *r, double *t)
{
	t_shape	pl[2];
	t_vec3	tmp;
	double	t1;
	double	t2;

	*t = -1;
	pl[0].p.normal = cy->normal;
	pl[1].p.normal = cy->normal;
	tmp = scale_vec3(cy->height / 2, &cy->normal);
	pl[0].p.center = sum_vec3(&cy->center, &tmp);
	pl[1].p.center = subst_vec3(&cy->center, &tmp);
	if (hit_plane(&pl[0], r, &t1) || hit_plane(&pl[1], r, &t2))
	{
		if (t1 < t2 && t1 > EPSILON)
			*t = t1;
		else if (t2 > EPSILON)
			*t = t2;
	}
	if (*t > EPSILON)
		return (true);
	return (false);
}
