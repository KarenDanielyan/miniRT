/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:50:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/07 12:52:20 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color map(uint32_t color)
{
	double r;
	double g;
	double b;

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
static t_color	texture_shader(t_control *ctl, t_hitrecord *hr)
{
	t_point3	lp;
	t_point2	uv;
	uint32_t	tcolor;
	t_color		color;

	(void)ctl;
	if (hr->hit->type == SPHERE)
	{
		lp = apply_transform_to_point( 
			&hr->hit->shape.sp.wtl_matrix, &hr->at);
		uv.x = (M_PI + atan2(get_y(&lp), get_x(&lp))) / (2 * M_PI);
		uv.y = (M_PI - acos(get_z(&lp) - vec3_length(&lp))) / M_PI;
		tcolor = ft_bitmap_get_pixel_color(hr->hit->material.texture_map, 
					(int)(uv.x * hr->hit->material.texture_map->ih.bi_width), 
					(int)(uv.y * hr->hit->material.texture_map->ih.bi_height));
		color = map(tcolor);
	}
	else
		color = hr->hit->material.color;
	return (color);
}

static t_color	checker_shader(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	(void)hr;
	return (vec3(0.0, 0.0, 0.0));
}

t_color	color_shader(t_control *ctl, t_hitrecord *hr)
{
	if (hr->hit->material.properties & TEXTURED)
		return (texture_shader(ctl, hr));
	else if (hr->hit->material.properties & CHECKERED)
		return (checker_shader(ctl, hr));
	else
		return (hr->hit->material.color);
}
