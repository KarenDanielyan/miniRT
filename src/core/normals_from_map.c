/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:35:24 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/10 18:32:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"
#include "quaternion.h"

static t_vec3	map_for_normals(t_ftbitmap *map, t_point2 uv)
{
	uint32_t	color;
	double		r;
	double		g;
	double		b;

	color = ft_bitmap_get_pixel_color(map, \
				(int)(uv.x * map->ih.bi_width), \
				(int)(uv.y * map->ih.bi_height));
	r = ((double)((color >> 16) & 0xFF) / 255.0f) * 2.0 - 1.0;
	g = ((double)((color >> 8) & 0xFF) / 255.0f) * 2.0 - 1.0;
	b = ((double )(color & 0xFF) / 255.0f) * 2.0 - 1.0;
	return (vec3(r, g, b));
}

static t_vec3	get_normal_for_sphere(t_point3 *at, t_hittable *hit)
{
	t_quaternion	t_to_world;
	t_hitrecord		hr;
	t_point2		uv;
	t_vec3			normal;
	t_vec3			z;

	hr.at = *at;
	hr.hit = hit;
	hr.normal = unit_vector(subst_vec3(at, &hit->shape.sp.center));
	z = vec3(0, 0, 1);
	t_to_world = get_quaternion(&z, &hr.normal);
	uv = compute_sphere_uv(&hr);
	normal = map_for_normals(hit->material.normal_map, uv);
	return (quarternion_rotate(&t_to_world, &normal));
}

static t_vec3	get_normal_for_plane(t_point3 *at, t_hittable *hit)
{
	t_quaternion	t_to_world;
	t_hitrecord		hr;
	t_point2		uv;
	t_vec3			z;
	t_vec3			normal;

	hr.at = *at;
	hr.hit = hit;
	z = vec3(0, 0, 1);
	t_to_world = get_quaternion(&z, &hit->shape.pl.normal);
	uv = compute_plane_uv(&hr);
	normal = map_for_normals(hit->material.normal_map, uv);
	return (quarternion_rotate(&t_to_world, &normal));
}

t_vec3	get_normal_from_map(t_point3 *at, t_hittable *hit)
{
	t_vec3			normal;

	normal = vec3(0, 0, 0);
	if (hit->type == SPHERE)
		normal = get_normal_for_sphere(at, hit);
	else if (hit->type == PLANE)
		normal = get_normal_for_plane(at, hit);
	return (normal);
}
