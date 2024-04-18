/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:28:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 19:09:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static inline float	difference(float a, float b)
{
	return (a - b);
}

bool	float_equal(float a, float b)
{
	if (difference(a, b) < EPSILON)
		return (true);
	return (false);
}
