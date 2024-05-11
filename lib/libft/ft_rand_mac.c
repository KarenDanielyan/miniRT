/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:34:05 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:34:19 by kdaniely         ###   ########.fr       */
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

double	ft_random_double_in_range(double min, double max)
{
	return (min + (max - min) * ((double)rand() / RAND_MAX));
}
#endif
