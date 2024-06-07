/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:50:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/07 17:23:08 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	texture_shader(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	(void)hr;
	return (vec3(0.0, 0.0, 0.0));
}

static t_color	checker_shader(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	(void)hr;
	t_point2	*uv;
	t_point3	at;

	uv = NULL;
	at = apply_transform_to_point(&hr->hit->shape.sp.wtl_matrix, &hr->at);
	uv->x = atan2(get_x(&at), get_y(&at)) / 2 * M_PI;
	uv->y = acos(get_z(&at)) / vec3_length(&at) / M_PI;
	if ((int)(uv->x + uv->y) % 2 == 0)
		return (vec3(0.1, 0.2, 0.3));
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
