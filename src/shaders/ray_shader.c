/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 03:55:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"


/**
 * @brief		Shader function for raytracing.
 * 
 * @param ctl 	control stucture of our program
 * @param r 	The ray we are going to use to test intersections.
 * @param pixel Pixel we want to color.
 * 
 * @details		We are going to use phong illumination model, but
 * 				we also want to implement global illumination.
 * 				Our shader will have 2 components:
 * 					1. Direct Illumination Contribution.
 * 					2. Indirect Illumincation contribution.
 * 				It will look something like this:
 * 				```C
 * 				diffuse = direct_diffuse + indirect_diffuse;
 * 				specular = direct_specular + indirect_specular;
 * 				color = ambient + diffuse + specular.
 * 				```
 */
void	ray_shader(t_control *ctl, t_ray *r, int *pixel)
{
	t_color		color;
	t_hitrecord	hr;

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
