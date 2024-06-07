/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:32:53 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/07 18:12:25 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

static t_vec3	get_normal_from_map(t_point3 *at, t_hittable *hit);
static t_vec3	get_cylinder_normal(t_point3 *at, t_hittable *hit);
static t_vec3	get_cone_normal(t_point3 *at, t_hittable *hit);

t_vec3	get_normal(t_point3 *at, t_hittable *hit)
{
	if (hit->material.normal_map == NULL)
	{
		if (hit->type == SPHERE)
			return (unit_vector(subst_vec3(at, &hit->shape.sp.center)));
		else if (hit->type == PLANE)
			return (unit_vector(hit->shape.pl.normal));
		else if (hit->type == CYLINDER)
			return (get_cylinder_normal(at, hit));
		else if (hit->type == CONE)
			return (get_cone_normal(at, hit));
	}
	return (get_normal_from_map(at, hit));
}

/**
 * @brief Get the cylinder normal object
 * 
 * @param at 
 * @param hit 
 * @return t_vec3 
 * 
 * @details		We need to steps to get the normal of a cylinder:
 * 					1. Figure out if at is on the caps or on the side.
 * 					2. Calculate the normal based on the step 1.
 * 
 */
static t_vec3	get_cylinder_normal(t_point3 *at, t_hittable *hit)
{
	t_point3		caps;
	t_point3		tmp;
	t_vec3			displacement;
	double			t;

	displacement = subst_vec3(at, &hit->shape.cy.center);
	t = vec3_dot(&displacement, &hit->shape.cy.normal);
	tmp = scale_vec3(hit->shape.cy.height / 2, &hit->shape.cy.normal);
	tmp = sum_vec3(&hit->shape.cy.center, &tmp);
	caps = subst_vec3(at, &tmp);
	if (vec3_length(&caps) <= hit->shape.cy.radius)
		return (hit->shape.cy.normal);
	tmp = scale_vec3(hit->shape.cy.height / 2, &hit->shape.cy.normal);
	tmp = subst_vec3(&hit->shape.cy.center, &tmp);
	caps = subst_vec3(at, &tmp);
	if (vec3_length(&caps) <= hit->shape.cy.radius)
		return (vec3_neg(&hit->shape.cy.normal));
	tmp = scale_vec3(t, &hit->shape.cy.normal);
	tmp = sum_vec3(&hit->shape.cy.center, &tmp);
	return (unit_vector(subst_vec3(at, &tmp)));
}

static t_vec3	get_cone_normal(t_point3 *at, t_hittable *hit)
{
	t_point3	local_hit;
	t_point3	delta;
	t_vec3		tmp;
	double		t;

	local_hit = apply_transform_to_point(&hit->shape.cn.wtl_matrix, at);
	if (float_equal(get_z(&local_hit), -hit->shape.cn.height))
		return (hit->shape.cn.normal);
	delta = subst_vec3(at, &hit->shape.cn.apex);
	t = vec3_length(&delta) / cos(hit->shape.cn.angle);
	tmp = scale_vec3(t, &hit->shape.cn.normal);
	tmp = sum_vec3(&hit->shape.cn.apex, &tmp);
	return (unit_vector(subst_vec3(at, &tmp)));
}

static t_vec3	get_normal_from_map(t_point3 *at, t_hittable *hit)
{
	t_hitrecord	hr;
	t_point2	uv;
	uint32_t	tnormal;
	t_color		normal;

	hr.at = *at;
	hr.hit = hit;
	if (hr.hit->type == SPHERE)
	{
		uv = compute_sphere_uv(&hr);
		tnormal = ft_bitmap_get_pixel_color(hr.hit->material.normal_map, \
					(int)(uv.x * hr.hit->material.normal_map->ih.bi_width), \
					(int)(uv.y * hr.hit->material.normal_map->ih.bi_height));
		normal = map(tnormal);
	}
	else
		normal = vec3(0.0, 0.0, 0.0);
	return (normal);
}
