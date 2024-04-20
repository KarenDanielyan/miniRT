/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:57:49 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/21 01:44:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

float	vec3_dot(const t_vec3 *u, const t_vec3 *v)
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

t_vec3	vec3_cross(const t_vec3 *u, const t_vec3 *v)
{
	return (vec3(u->e[1] * v->e[2] - u->e[2] * v->e[1], \
				u->e[2] * v->e[0] - u->e[0] * v->e[2], \
				u->e[0] * v->e[1] - u->e[1] * v->e[0]));
}

t_vec3	unit_vector(t_vec3 v)
{
	return (shrink_vec3(vec3_length(&v), &v));
}

float	vec3_length(t_vec3 *self)
{
	return (sqrt(vec3_length_squared(self)));
}

float	vec3_length_squared(t_vec3 *self)
{
	return (self->e[0] * self->e[0] + self->e[1] * self->e[1] \
		+ self->e[2] * self->e[2]);
}
