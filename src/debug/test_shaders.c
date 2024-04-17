/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:52:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/17 19:42:42 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

t_color	normal_shpere_shader(t_ray *r, float t, t_sphere *sp)
{
	t_color		color;
	t_point3	p;

	p = ray_at(r, t);
	color = unit_vector(subst_vec3(&p, &sp->center));
	color = vec3(get_x(&color) + 1.0, \
		get_y(&color) + 1.0, get_z(&color) + 1);
	color = shrink_vec3(2, &color);
	return (color);
}
