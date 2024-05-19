/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarternion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:54:26 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 01:44:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "quaternion.h"
#include "vec3.h"

t_quaternion	new_quaternion(float i, float j, float k, float w)
{
	t_quaternion	q;

	q.i = i;
	q.j = j;
	q.k = k;
	q.w = w;
	return (q);
}

t_quaternion	rodrigues_rotation(t_vec3 *v, float angle)
{
	t_quaternion	q;
	float			sin_a;

	sin_a = sin(angle / 2);
	q.i = get_x(v) * sin_a;
	q.j = get_y(v) * sin_a;
	q.k = get_z(v) * sin_a;
	q.w = cos(angle / 2);
	return (q);
}

t_quaternion	quaternion_inverse(t_quaternion *q)
{
	float			norm;
	t_quaternion	qi;

	norm = 1.0 / (q->i * q->i + q->j * q->j + q->k * q->k + q->w * q->w);
	qi.i = -q->i * norm;
	qi.j = -q->j * norm;
	qi.k = -q->k * norm;
	qi.w = q->w * norm;
	return (qi);
}

t_quaternion	quaternion_multiply(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	q;

	q.i = q1->w * q2->i + q1->i * q2->w + q1->j * q2->k - q1->k * q2->j;
	q.j = q1->w * q2->j - q1->i * q2->k + q1->j * q2->w + q1->k * q2->i;
	q.k = q1->w * q2->k + q1->i * q2->j - q1->j * q2->i + q1->k * q2->w;
	q.w = q1->w * q2->w - q1->i * q2->i - q1->j * q2->j - q1->k * q2->k;
	return (q);
}

t_vec3	quarternion_rotate(t_quaternion *q, t_vec3 *v)
{
	t_quaternion	vq;
	t_quaternion	qi;
	t_quaternion	r;
	t_quaternion	res;

	vq = new_quaternion(get_x(v), get_y(v), get_z(v), 0);
	qi = quaternion_inverse(q);
	r = quaternion_multiply(q, &vq);
	res = quaternion_multiply(&r, &qi);
	return (vec3(res.i, res.j, res.k));
}
