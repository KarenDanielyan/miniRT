/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:57:49 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 19:17:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	unit_vector(t_vec3 v)
{
	return (shrink_vec3(vec3_length(&v), &v));
}

double	vec3_length(t_vec3 *self)
{
	return (sqrt(vec3_length_squared(self)));
}

double	vec3_length_squared(t_vec3 *self)
{
	return (self->e[0] * self->e[0] + self->e[1] * self->e[1] \
		+ self->e[2] * self->e[2]);
}

void	vec3_normalize(t_vec3 *self)
{
	vec3_div(self, vec3_length(self));
}
