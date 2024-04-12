/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 16:56:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"
#include "camera.h"

t_color	ray_color(t_ray *ray)
{
	t_color	c;
	t_vec3	uv;
	float	a;

	uv = unit_vector(ray->direction);
	a = 0.5 * (get_y(&uv) + 1.0);
	c = vec3(1.0, 1.0, 1.0);
	uv = vec3(0.5, 0.7, 1.0);
	c = scale_vec3((1 - a), &c);
	uv = scale_vec3(a, &uv);
	c = sum_vec3(&c, &uv);
	return (c);
}

void	ray_shader(t_control *ctl, t_ray *r, int *pixel)
{
	t_color	color;

	(void)ctl;
	color = ray_color(r);
	set_color(pixel, color);
}
