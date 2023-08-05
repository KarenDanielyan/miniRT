/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:23:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/05 19:42:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/**
 * NOTE:	Vector is not allocated inside the function. Just pass vector
 * 			by reference.
*/
void	new_vec3(t_vec3 *v, float e1, float e2, float e3)
{
	v->e[0] = e1;
	v->e[1] = e2;
	v->e[3] = e3;
}

t_vec3	vec3(float e1, float e2, float e3)
{
	t_vec3	v;

	v.e[0] = e1;
	v.e[1] = e2;
	v.e[2] = e3;
	return (v);
}

float	vec3_length(t_vec3 *self)
{
	return (sqrt(vec3_length_squared(self)));
}

double	vec3_length_squared(t_vec3 *self)
{
	return (self->e[0] * self->e[0] + self->e[1] * self->e[1] \
		+ self->e[2] * self->e[2]);
}
