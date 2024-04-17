/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 19:44:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

void	ray_shader(t_control *ctl, t_ray *r, int *pixel)
{
	t_color		color;
	t_hitrecord	hr;

	(void)ctl;
	if (hit_anything(r, &ctl->world, &hr) == false)
		color = skybox_shader(r);
	else
	{
		if (hr.hit->type == SPHERE)
			color = normal_shpere_shader(r, hr.t, &hr.hit->shape.s);
		else
			color = skybox_shader(r);
	}
	set_color(pixel, color);
}
