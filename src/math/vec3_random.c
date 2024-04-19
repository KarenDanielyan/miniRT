/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:16:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 21:03:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec3	random_unit_vector(uint32_t *rng_state)
{
	return (unit_vector(vec3(\
		random_value(rng_state), \
		random_value(rng_state), \
		random_value(rng_state))));
}

t_vec3	random_hemisphere_vector(uint32_t *rng_state)
{
	return (unit_vector(vec3(\
		normal_ditributed_value(rng_state), \
		normal_ditributed_value(rng_state), \
		normal_ditributed_value(rng_state))));
}
