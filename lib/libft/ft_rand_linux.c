/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:33:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:34:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/random.h>

#ifdef __linux__
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
