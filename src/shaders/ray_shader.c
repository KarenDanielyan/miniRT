/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 21:15:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr);
t_color	indirect_illumination(t_control *ctl, \
	t_hitrecord *hr, int bounce);

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
 * 					di = di_ambient + di_diffuse + di_specular;
 * 					idi = idi_diffuse + idi_specular;
 * 					color = di + idi;
 * 				```
 */
t_color	ray_shader(t_control *ctl, t_ray *r, int bounce)
{
	t_color		color;
	t_color		di;
	t_color		idi;
	t_hitrecord	hr;

	di = vec3(0, 0, 0);
	idi = vec3(0, 0, 0);
	if (hit_anything(r, &ctl->world, &hr) == false)
		color = skybox_shader(r);
	else
	{
		if (!GI)
			di = direct_illumination(ctl, &hr);
		if (GI)
		{
			idi = indirect_illumination(ctl, &hr, bounce);
			idi = scale_vec3(0.5, &idi);
		}
		color = sum_vec3(&di, &idi);
	}
	return (color);
}

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	if (hr->hit->type == SPHERE)
		return (normal_shpere_shader(&hr->at, &hr->hit->shape.s));
	return (vec3(0.0, 0.0, 0.0));
}

t_color	indirect_illumination(t_control *ctl, \
	t_hitrecord *hr, int bounce)
{
	t_ray	r;
	t_vec3	direction;

	direction = random_hemisphere_vector(&ctl->rng_state);
	if (vec3_dot(&direction, &hr->normal) < 0)
		direction = vec3_neg(&direction);
	if (bounce >= 0)
	{
		new_ray(&r, hr->at, direction);
		return (ray_shader(ctl, &r, bounce - 1));
	}
	return (skybox_shader(&r));
}
