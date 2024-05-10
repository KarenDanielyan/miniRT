/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:17:03 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 22:53:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_scalar_mult(const t_vec3 *u, const t_vec3 *v)
{
	return (vec3(\
			u->e[0] * v->e[0], \
			u->e[1] * v->e[1], \
			u->e[2] * v->e[2]));
}

double	vec3_dot(const t_vec3 *u, const t_vec3 *v)
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

t_vec3	vec3_cross(const t_vec3 *u, const t_vec3 *v)
{
	return (vec3(u->e[1] * v->e[2] - u->e[2] * v->e[1], \
				u->e[2] * v->e[0] - u->e[0] * v->e[2], \
				u->e[0] * v->e[1] - u->e[1] * v->e[0]));
}

t_vec3	vec3_lerp(const t_vec3 *u, const t_vec3 *v, double t)
{
	return (vec3(\
			u->e[0] * t + (1 - t) * v->e[0], \
			u->e[1] * t + (1 - t) * v->e[1], \
			u->e[2] * t + (1 - t) * v->e[2]));
}
