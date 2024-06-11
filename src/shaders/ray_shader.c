/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/11 19:33:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr);
t_color	scatter(t_control *ctl, t_hitrecord *hr, int bounce);

/**
 * @brief		Shader function for raytracing.
 * 
 * @param ctl 		The control stucture of our program.
 * @param r 		The ray we are going to use to test intersections.
 * @param bounce 	Number of times the ray can bounce in the scene.
 * 
 * @details		We are going to use blinn-phong illumination model.
 * 				At first we also wanted to implement global illumination,
 * 				but Whitted's ray tracing algorithm can't handle it.
 */
t_color	ray_shader(t_control *ctl, t_ray *r, int bounce)
{
	t_hitrecord	hr;
	t_color		di;
	t_color		gi;

	gi = vec3(0, 0, 0);
	if (bounce <= 0)
		return (vec3(0, 0, 0));
	if (hit_anything(r, &ctl->world, &hr))
	{
		hr.surface_color = color_shader(&hr);
		di = direct_illumination(ctl, &hr);
		if (hr.hit->material.properties & METALLIC || \
			hr.hit->material.properties & DIELECTRIC)
			gi = scatter(ctl, &hr, bounce);
		return (sum_vec3(&di, &gi));
	}
	return (skybox_shader(ctl, r));
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
	t_color	diffuse_and_specular;
	t_color	res;

	ambient = ambient_shader(ctl, hr);
	diffuse_and_specular = blinn_phong_shader(ctl, hr);
	res = sum_vec3(&ambient, &diffuse_and_specular);
	return (res);
}

t_color	scatter(t_control *ctl, t_hitrecord *hr, int bounce)
{
	t_ray	scattered;
	t_color	color;

	scattered.origin = hr->at;
	if (hr->hit->material.properties & METALLIC)
		scattered.direction = ray_reflect(&hr->r.direction, &hr->normal);
	color = ray_shader(ctl, &scattered, bounce - 1);
	color = vec3_scalar_mult(&color, &hr->surface_color);
	return (color);
}
