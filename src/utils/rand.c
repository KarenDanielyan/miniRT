/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:51:21 by kdaniely         ###   ########.fr       */
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

double	random_double(void)
{
	uint32_t	buf;

	getrandom(&buf, sizeof(buf), GRND_RANDOM);
	return ((double)buf / UINT32_MAX);
}

/* Normally distributed number with mean=0 and sd=1 */
double	random_gaussian_value(void)
{
	double	theta;
	double	rho;

	theta = 2 * M_PI * random_double();
	rho = sqrt(-2 * log(random_double()));
	return (rho * cos(theta));
}
