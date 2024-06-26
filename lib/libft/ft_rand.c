/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 15:34:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/random.h>

/* Normally distributed number with mean=0 and sd=1 */
double	ft_random_gaussian_value(void)
{
	double	theta;
	double	rho;

	theta = 2 * M_PI * ft_random_double();
	rho = sqrt(-2 * log(ft_random_double()));
	return (rho * cos(theta));
}
