/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:32:53 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 18:46:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

t_vec3	get_normal(t_ray *r, t_point3 *at, t_hittable *hit)
{
	(void)r;
	if (hit->type == SPHERE)
		return (unit_vector(subst_vec3(at, &hit->shape.s.center)));
	return (vec3(0.0, 0.0, 0.0));
}
