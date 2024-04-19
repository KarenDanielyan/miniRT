/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 18:08:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <math.h>

float	random_value(uint32_t *rng_state)
{
	uint32_t	result;

	*rng_state = *rng_state * 747796405 + 2891336453;
	result = ((*rng_state >> ((*rng_state >> 28) + 4)) ^ *rng_state) \
		* 277803737;
	result = (result >> 22) ^ result;
	return (result / (float)(UINT32_MAX));
}

/* Normally distributed number with mean=0 and sd=1 */
float	normal_ditributed_value(uint32_t *rng_state)
{
	float	theta;
	float	rho;

	theta = 2 * M_PI * random_value(rng_state);
	rho = sqrtf(-2 * logf(random_value(rng_state)));
	return (rho * cosf(theta));
}
