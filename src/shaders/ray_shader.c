/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/02 23:20:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	direct_illumination(t_control *ctl, t_hitrecord *hr);

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

	if (bounce <= 0)
		return (vec3(0, 0, 0));
	if (hit_anything(r, &ctl->world, &hr))
		return (direct_illumination(ctl, &hr));
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
