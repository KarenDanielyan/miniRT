/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:34:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 19:17:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_neg(t_vec3 *self)
{
	return (vec3(self->e[0] * -1,
			self->e[1] * -1,
			self->e[2] * -1));
}

void	vec3_sum(t_vec3 *self, t_vec3 *v)
{
	self->e[0] += v->e[0];
	self->e[1] += v->e[1];
	self->e[2] += v->e[2];
}

void	vec3_mult(t_vec3 *self, const double t)
{
	self->e[0] *= t;
	self->e[1] *= t;
	self->e[2] *= t;
}

void	vec3_div(t_vec3 *self, const double t)
{
	vec3_mult(self, (1 / t));
}
