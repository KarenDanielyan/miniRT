/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:52:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 16:46:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

t_color	normal_shpere_shader(t_point3 *hit_p, t_sphere *sp)
{
	t_color		color;

	color = unit_vector(subst_vec3(hit_p, &sp->center));
	color = vec3(get_x(&color) + 1.0, \
		get_y(&color) + 1.0, get_z(&color) + 1);
	color = shrink_vec3(2, &color);
	return (color);
}
