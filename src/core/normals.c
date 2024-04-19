/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:32:53 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 20:21:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

t_vec3	get_normal(t_point3 *at, t_hittable *hit)
{
	if (hit->type == SPHERE)
		return (unit_vector(subst_vec3(at, &hit->shape.s.center)));
	return (vec3(0.0, 0.0, 0.0));
}
