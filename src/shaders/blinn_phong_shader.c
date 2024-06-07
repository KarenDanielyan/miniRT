/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blinn_phong_shader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:38:40 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/04 13:56:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	compute_for_ls(t_control *ctl, t_hitrecord *hr, t_light *l);

/**
 * @brief		Compute the color of the object using Blinn-Phong model.
 * 				The only component missing here is the ambient component.
 * 
 * @param ctl	Control structure.
 * @param hr	Hit record.
 * @return t_color	The color of the object on hit point.
 */
t_color	blinn_phong_shader(t_control *ctl, t_hitrecord *hr)
{
	t_color		color;
	t_light		*l;
	t_color		tmp;
	size_t		i;

	color = vec3(0.0, 0.0, 0.0);
	i = 0;
	while (i < ctl->lights.nmemb)
	{
		l = ft_darray_get_by_index(&ctl->lights, i);
		if (l->type == POINT)
		{
			if (vec3_dot(&hr->normal, &hr->r.direction) < 0.0)
			{
				tmp = compute_for_ls(ctl, hr, l);
				color = sum_vec3(&color, &tmp);
			}
		}
		i++;
	}
	return (vec3(\
		clamp_d(get_x(&color), 0.000, 1.000), \
		clamp_d(get_y(&color), 0.000, 1.000), \
		clamp_d(get_z(&color), 0.000, 1.000)));
}

static t_color	compute_specular(t_light *light, t_hitrecord *hr, t_ray *l)
{
	t_vec3	h;
	t_vec3	v;
	t_color	color;
	double	intensity;

	v = vec3_neg(&hr->r.direction);
	h = sum_vec3(&l->direction, &v);
	vec3_normalize(&h);
	intensity = pow(fmax(0.0, vec3_dot(&hr->normal, &h)), \
		hr->hit->material.shininess);
	color = scale_vec3(intensity * hr->hit->material.specular, &light->color);
	return (color);
}

static t_color	compute_for_ls(t_control *ctl, t_hitrecord *hr, t_light *l)
{
	t_hitrecord	tmp_hr;
	t_color		color;
	t_color		specular;
	t_ray		r;

	color = vec3(0.0, 0.0, 0.0);
	new_ray(&r, l->position, subst_vec3(&hr->at, &l->position));
	if (hit_anything(&r, &ctl->world, &tmp_hr) && tmp_hr.hit == hr->hit)
	{
		r.direction = vec3_neg(&r.direction);
		color = color_shader(ctl, hr);
		color = vec3_scalar_mult(&color, &l->color);
		color = scale_vec3(fmax(0.0, vec3_dot(&hr->normal, &r.direction)), \
								&color);
		specular = compute_specular(l, hr, &r);
		color = sum_vec3(&color, &specular);
		color = scale_vec3(l->brightness, &color);
	}
	return (color);
}
