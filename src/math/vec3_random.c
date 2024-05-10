/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:16:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 18:26:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec3	random_vector(void)
{
	return (unit_vector(vec3(\
		ft_random_double(), \
		ft_random_double(), \
		ft_random_double())));
}

t_vec3	random_hemisphere_vector(t_vec3 *normal)
{
	t_vec3	in_unit_sphere;

	in_unit_sphere = unit_vector(vec3(\
		ft_random_gaussian_value(), \
		ft_random_gaussian_value(), \
		ft_random_gaussian_value()));
	if (vec3_dot(&in_unit_sphere, normal) < 0.0)
		return (vec3_neg(&in_unit_sphere));
	return (in_unit_sphere);
}

t_vec3	random_sphere_vector(void)
{
	return (unit_vector(vec3(\
		ft_random_gaussian_value(), \
		ft_random_gaussian_value(), \
		ft_random_gaussian_value())));
}

t_vec3	random_unit_vector(void)
{
	t_vec3	v;

	while (true)
	{
		new_vec3(&v, \
			ft_random_double_in_range(-1, 1), \
			ft_random_double_in_range(-1, 1), \
			ft_random_double_in_range(-1, 1));
		if (vec3_length_squared(&v) < 1.0)
			return (unit_vector(v));
	}
}
