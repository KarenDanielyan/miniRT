/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:50:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/12 16:59:15 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	map(uint32_t color)
{
	double	r;
	double	g;
	double	b;

	r = (double)((color >> 16) & 0xFF) / 255.0f;
	g = (double)((color >> 8) & 0xFF) / 255.0f;
	b = (double )(color & 0xFF) / 255.0f;
	return (vec3(r, g, b));
}

/* Planar projection for planes and Spherical projection for spheres */
/* Spherical projection: 
	x = [pi + atan2(y,x)] / 2pi 
	y = [pi - acos(z / ||x||)] / pi
*/
t_color	texture_shader(t_hitrecord *hr)
{
	t_point2	uv;
	uint32_t	tcolor;
	t_color		color;

	if (hr->hit->type == SPHERE)
		uv = compute_sphere_uv(hr);
	else if (hr->hit->type == PLANE)
		uv = compute_plane_uv(hr);
	tcolor = ft_bitmap_get_pixel_color(hr->hit->material.texture_map, \
			(int)(uv.x * hr->hit->material.texture_map->ih.bi_width), \
			(int)(uv.y * hr->hit->material.texture_map->ih.bi_height));
	color = map(tcolor);
	return (color);
}

static t_color	checker_shader(t_hitrecord *hr)
{
	t_point2	uv;
	t_point		c;
	
	if (hr->hit->type == SPHERE)
		uv = compute_sphere_uv(hr);
	else
		uv = compute_plane_uv(hr);
	c.u = floor(uv.x * CHECKER_WIDTH);
	c.v = floor(uv.y * CHECKER_HEIGHT);
	if ((int)(c.u + c.v) % 2 == 0)
		return (vec3(1, 1, 1));
	return (vec3(0.0, 0.0, 0.0));
}

t_color	color_shader(t_hitrecord *hr)
{
	if (hr->hit->material.properties & TEXTURED)
		return (texture_shader(hr));
	else if (hr->hit->material.properties & CHECKERED)
		return (checker_shader(hr));
	else
		return (hr->hit->material.color);
}
