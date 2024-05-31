/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:54:26 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/01 02:47:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "quaternion.h"
#include "vec3.h"

/**
 * @brief		get_quaternion() returns a quaternion that represents
 * 				the rotation from vector u to vector v.
 * 
 * @param u 	Pointer to the first vector.
 * @param v 	Pointer to the second vector.
 * @return 		The quaternion that represents the rotation.
 */
t_quaternion	get_quaternion(t_vec3 *u, t_vec3 *v)
{
	t_vec3			rod;
	float			theta;

	theta = acos(vec3_dot(u, v));
	rod = vec3_cross(u, v);
	if (vec3_length(&rod) < EPSILON)
	{
		if (theta > EPSILON)
			return (quaternion(0, 1, 0, 0));
		if (theta < EPSILON)
			return (quaternion(0, 0, 0, 1));
	}
	rod = unit_vector(rod);
	return (rodrigues_rotation(&rod, theta));
}

t_quaternion	rodrigues_rotation(t_vec3 *rod, float angle)
{
	t_quaternion	q;
	float			sin_a;

	sin_a = sin(angle / 2);
	q.i = get_x(rod) * sin_a;
	q.j = get_y(rod) * sin_a;
	q.k = get_z(rod) * sin_a;
	q.w = cos(angle / 2);
	return (q);
}

t_quaternion	quaternion_conjugate(t_quaternion *q)
{
	t_quaternion	qi;

	qi.w = q->w;
	qi.i = -q->i;
	qi.j = -q->j;
	qi.k = -q->k;
	return (qi);
}

t_quaternion	quaternion_multiply(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	q;

	q.w = q1->w * q2->w - q1->i * q2->i - q1->j * q2->j - q1->k * q2->k;
	q.i = q1->w * q2->i + q1->i * q2->w + q1->j * q2->k - q1->k * q2->j;
	q.j = q1->w * q2->j - q1->i * q2->k + q1->j * q2->w + q1->k * q2->i;
	q.k = q1->w * q2->k + q1->i * q2->j - q1->j * q2->i + q1->k * q2->w;
	return (q);
}

t_vec3	quarternion_rotate(t_quaternion *q, t_vec3 *v)
{
	t_quaternion	vq;
	t_quaternion	qi;
	t_quaternion	r;
	t_quaternion	res;

	vq = quaternion(get_x(v), get_y(v), get_z(v), 0);
	qi = quaternion_conjugate(q);
	r = quaternion_multiply(q, &vq);
	res = quaternion_multiply(&r, &qi);
	return (vec3(res.i, res.j, res.k));
}
