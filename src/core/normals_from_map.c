/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:35:24 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/10 15:36:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

t_vec3	get_normal_from_map(t_point3 *at, t_hittable *hit)
{
	t_hitrecord	hr;
	t_point2	uv;
	t_vec3		normal;
	t_vec3		tmp;

	hr.at = *at;
	hr.hit = hit;
	if (hr.hit->type == SPHERE)
	{
		uv = compute_sphere_uv(&hr);
		normal = unit_vector(subst_vec3(at, &hit->shape.sp.center));
	}
	else if (hr.hit->type == PLANE)
	{
		tmp = apply_transform_to_point(&hit->shape.pl.wtl_matrix, at);
		uv.x = fabs(modf(get_x(&tmp), &hr.t));
		uv.y = fabs(modf(get_y(&tmp), &hr.t));
		normal = hit->shape.pl.normal;
	}
	tmp = map(ft_bitmap_get_pixel_color(hr.hit->material.normal_map, \
				(int)(uv.x * hr.hit->material.normal_map->ih.bi_width), \
				(int)(uv.y * hr.hit->material.normal_map->ih.bi_height)));
	if (vec3_length(&tmp) != 0)
		normal = unit_vector(sum_vec3(&tmp, &normal));
	return (normal);
}
