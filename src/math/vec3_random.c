/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:16:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec3	random_vector(void)
{
	return (unit_vector(vec3(\
		random_float(), \
		random_float(), \
		random_float())));
}

t_vec3	random_hemisphere_vector(void)
{
	return (unit_vector(vec3(\
		normal_ditributed_value(), \
		normal_ditributed_value(), \
		normal_ditributed_value())));
}

/*t_vec3	random_hemisphere_vector(uint32_t *rng_state)
{
	t_vec3	tmp;

	(void)rng_state;
	while(true)
	{
		tmp = random_vector(NULL);
		if (vec3_length_squared(&tmp) < 1)
			return (unit_vector(tmp));
	}
}*/
