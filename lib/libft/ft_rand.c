/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/07 16:44:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/random.h>


#ifdef __APPLE__

float	ft_random_float(void)
{
	return ((float)rand() / RAND_MAX);
}

double	ft_random_double(void)
{
	return ((double)rand() / RAND_MAX);
}

double ft_random_double_in_range(double min, double max)
{
	return (min + (max - min) * ((double)rand() / RAND_MAX));
}

#elif __linux__
/* Random float [0;1) */
float	ft_random_float(void)
{
	uint32_t	buf;

	getrandom(&buf, sizeof(buf), GRND_RANDOM);
	return ((float)buf / UINT32_MAX);
}

/* Random double [0; 1) */
double	ft_random_double(void)
{
	uint32_t	buf;

	getrandom(&buf, sizeof(buf), GRND_RANDOM);
	return ((double)buf / UINT32_MAX);
}

/* Random double in range [min; max) */
double	ft_random_double_in_range(double min, double max)
{
	uint32_t	buf;

	getrandom(&buf, sizeof(buf), GRND_RANDOM);
	return (min + (max - min) * ((double)buf / UINT32_MAX));
}
#endif

/* Normally distributed number with mean=0 and sd=1 */
double	ft_random_gaussian_value(void)
{
	double	theta;
	double	rho;

	theta = 2 * M_PI * ft_random_double();
	rho = sqrt(-2 * log(ft_random_double()));
	return (rho * cos(theta));
}