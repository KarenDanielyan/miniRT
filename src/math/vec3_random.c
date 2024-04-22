/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:16:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:50:41 by kdaniely         ###   ########.fr       */
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
