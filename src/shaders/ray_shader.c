/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 02:57:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

void	ray_shader(t_control *ctl, t_ray *r, int *pixel)
{
	t_color	color;
	float	t;
	t_point3	p;
	t_point3	sp;
	

	(void)ctl;
	sp = vec3(0.0, 0.0, -1.0);
	t = sphere_hit(sp, 0.3, r);
	p = ray_at(r, t);
	if (t > 0.0)
	{
		color = unit_vector(subst_vec3(&p, &sp));
		color = vec3(get_x(&color) + 1.0, get_y(&color) + 1.0, get_z(&color) + 1);
		color = shrink_vec3(2, &color);
	}
	else
		color = skybox_shader(r);
	set_color(pixel, color);
}
