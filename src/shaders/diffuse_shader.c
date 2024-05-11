/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:38:40 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 16:22:35 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	diffuse_shader(t_control *ctl, t_hitrecord *hr)
{
	t_light		l;
	t_hitrecord	tmp_hr;
	t_color		color;
	t_ray		r;

	l.pos = vec3(-1, 0, 0);
	l.color = vec3(1.0, 1.0, 1.0);
	color = vec3(0.0, 0.0, 0.0);
	new_ray(&r, l.pos, subst_vec3(&hr->at, &l.pos));
	if (hit_anything(&r, &ctl->world, &tmp_hr) && tmp_hr.hit == hr->hit)
	{
		r.direction = vec3_neg(&r.direction);
		color = vec3_scalar_mult(&hr->hit->material.color, &l.color);
		color = scale_vec3(fmax(0.0, vec3_dot(&hr->normal, &r.direction)), \
								&color);
	}
	return (color);
}
