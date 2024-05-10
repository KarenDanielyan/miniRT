/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 01:12:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "miniRT.h"
#include "defines.h"
#include "camera.h"
#include "shapes.h"

static t_color	direct_illumination(t_control *ctl, t_hitrecord *hr);
static t_color	global_illumination(t_control *ctl, \
	t_hitrecord *hr, int bounce);

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
	di = skybox_shader(r);
	new_vec3(&di, 0, 0, 0);
	new_vec3(&gi, 0, 0, 0);
	if (hit_anything(r, &ctl->world, &hr))
	{
		di = direct_illumination(ctl, &hr);
		if (GI)
		{
			gi = global_illumination(ctl, &hr, bounce);
			gi = vec3_scalar_mult(&gi, &hr.hit->material.color);
		}
	}
	return (vec3_lerp(&di, &gi, 0.7));
}

/**
 * @brief			Shader function for direct illumination.
 * 
 * @param ctl		Control Structure.
 * @param hr		Hir record.
 * @return t_color	Color conponent from the direct illumination.
 */
t_color	direct_illumination(t_control *ctl, t_hitrecord *hr)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	res;

	ambient = vec3(1.0, 1.0, 1.0);
	ambient = vec3_scalar_mult(&hr->hit->material.color, &ambient);
	ambient = scale_vec3(0.1, &ambient);
	diffuse = diffuse_shader(ctl, hr);
	specular = vec3(0.0, 0.0, 0.0);
	res = sum_vec3(&ambient, &diffuse);
	res = sum_vec3(&res, &specular);
	return (res);
}

t_color	global_illumination(t_control *ctl, t_hitrecord *hr, int bounce)
{
	t_ray	r;
	t_vec3	direction;

	direction = random_sphere_vector();
	direction = sum_vec3(&hr->normal, &direction);
	new_ray(&r, hr->at, unit_vector(direction));
	return (ray_shader(ctl, &r, bounce - 1));
}
