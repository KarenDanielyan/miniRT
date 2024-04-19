/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 16:48:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	random_value(uint32_t *rng_state)
{
	uint32_t	result;

	*rng_state = *rng_state * 747796405 + 2891336453;
	result = ((*rng_state >> ((*rng_state >> 28) + 4)) ^ *rng_state) \
		* 277803737;
	result = (result >> 22) ^ result;
	return (result / (float)(UINT32_MAX));
}
