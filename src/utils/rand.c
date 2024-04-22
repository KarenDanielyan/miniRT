/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <math.h>
#include <sys/random.h>
#include <stdio.h>

/* Random float [0;1) */
float	random_float(void)
{
	uint32_t	buf;

	getrandom(&buf, sizeof(buf), GRND_RANDOM);
	return ((float)buf / UINT32_MAX);
}

/* Normally distributed number with mean=0 and sd=1 */
float	normal_ditributed_value(void)
{
	float	theta;
	float	rho;

	theta = 2 * M_PI * random_float();
	rho = sqrt(-2 * log(random_float()));
	return (rho * cos(theta));
}
