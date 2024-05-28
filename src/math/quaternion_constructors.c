/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_constructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:47:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 16:52:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	quaternion(double i, double j, double k, double w)
{
	t_quaternion	q;

	q.i = i;
	q.j = j;
	q.k = k;
	q.w = w;
	return (q);
}

void	new_quaternion(t_quaternion *q, t_vec3 *u, float w)
{
	q->i = get_x(u);
	q->j = get_y(u);
	q->k = get_z(u);
	q->w = w;
}
