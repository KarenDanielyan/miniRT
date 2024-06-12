/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/12 00:40:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	make_reflected_ray(t_hitrecord *hr)
{
	t_vec3	reflected;
	t_vec3	fuzz;

	reflected = ray_reflect(&hr->r.direction, &hr->normal);
	fuzz = random_sphere_vector();
	fuzz = scale_vec3((1.0 - hr->hit->material.glossiness), &fuzz);
	reflected = unit_vector(sum_vec3(&reflected, &fuzz));
	return (reflected);
}

t_vec3	make_refracted_ray(t_hitrecord *hr)
{
	double	ri;
	double	cos_theta;
	double	sin_theta;

	if (vec3_dot(&hr->r.direction, &hr->normal) > 0)
		ri = hr->hit->material.ri;
	else
		ri = 1.0 / hr->hit->material.ri;
	cos_theta = fmin(vec3_dot(&hr->r.direction, &hr->normal), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	if (ri * sin_theta > 1.0)
		return (ray_reflect(&hr->r.direction, &hr->normal));
	return (ray_refract(&hr->r.direction, &hr->normal, ri));
}

t_color	scatter(t_control *ctl, t_hitrecord *hr, int bounce)
{
	t_ray	scattered;
	t_color	color;

	scattered.origin = hr->at;
	if (hr->hit->material.properties & METALLIC)
		scattered.direction = make_reflected_ray(hr);
	else if (hr->hit->material.properties & DIELECTRIC)
		scattered.direction = make_refracted_ray(hr);
	color = ray_shader(ctl, &scattered, bounce - 1);
	color = vec3_scalar_mult(&color, &hr->surface_color);
	return (color);
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
