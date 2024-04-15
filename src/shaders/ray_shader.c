/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/16 01:01:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

void	ray_shader(t_control *ctl, t_ray *r, int *pixel)
{
	t_color	color;

	(void)ctl;
	if (sphere_hit(vec3(0.0, 0.0, -1.0), 0.3, r) > 0.0)
		color = vec3(1.0, 0.0, 0.0);
	else
		color = skybox_shader(r);
	set_color(pixel, color);
}
