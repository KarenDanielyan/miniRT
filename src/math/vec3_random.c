/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:16:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 18:31:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec3	random_vector(void)
{
	return (unit_vector(vec3(\
		random_double(), \
		random_double(), \
		random_double())));
}

t_vec3	random_hemisphere_vector(void)
{
	return (unit_vector(vec3(\
		random_gaussian_value(), \
		random_gaussian_value(), \
		random_gaussian_value())));
}

t_vec3	random_unit_vector(void)
{
	t_vec3	v;

	while(true)
	{
		new_vec3(&v, \
			random_double_in_range(-1, 1), \
			random_double_in_range(-1, 1), \
			random_double_in_range(-1, 1));
		if (vec3_length_squared(&v) < 1.0)
			return (unit_vector(v));
	}
}
