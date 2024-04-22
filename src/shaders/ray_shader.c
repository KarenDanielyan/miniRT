/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:12:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr);
t_color	global_illumination(t_control *ctl, t_hitrecord *hr, int bounce);

/**
 * @brief		Shader function for raytracing.
 * 
 * @param ctl 		The control stucture of our program.
 * @param r 		The ray we are going to use to test intersections.
 * @param bounce 	Number of times the ray can bounce in the scene.
 * 
 * @details		We are going to use phong illumination model, but
 * 				we also want to implement global illumination.
 * 				Our shader will have 2 components:
 * 					1. Direct Illumination Contribution.
 * 					2. Indirect or Global Illumincation contribution.
 * 				It will look something like this:
 * 				```C
 * 					di = di_ambient + di_diffuse + di_specular;
 * 					gi = gi_diffuse + gi_specular;
 * 					color = di + idi;
 * 				```
 */
t_color	ray_shader(t_control *ctl, t_ray *r, int bounce)
{
	t_color		di;
	t_color		gi;
	t_hitrecord	hr;

	if (bounce <= 0)
		return (vec3(0, 0, 0));
	new_vec3(&gi, 0, 0, 0);
	if (hit_anything(r, &ctl->world, &hr) == false)
		return (skybox_shader(r));
	di = direct_illumination(ctl, &hr);
	if (GI)
	{
		gi = global_illumination(ctl, &hr, bounce);
		vec3_mult(&gi, 0.5);
	}
	sum_vec3(&di, &gi);
	return (gi);
}

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	if (hr->hit->type == SPHERE)
		return (normal_shpere_shader(&hr->at, &hr->hit->shape.s));
	return (vec3(0.0, 0.0, 0.0));
}

t_color	global_illumination(t_control *ctl, t_hitrecord *hr, int bounce)
{
	t_ray	r;
	t_vec3	direction;

	direction = random_hemisphere_vector();
	if (vec3_dot(&direction, &hr->normal) < 0.0)
		direction = vec3_neg(&direction);
	new_ray(&r, hr->at, direction);
	return (ray_shader(ctl, &r, bounce - 1));
}
