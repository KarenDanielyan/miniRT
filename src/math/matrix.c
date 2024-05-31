/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:46:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/01 03:37:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "quaternion.h"

t_matrix	matrix_identity(void)
{
	t_matrix	m;

	m.e[0][0] = 1;
	m.e[0][1] = 0;
	m.e[0][2] = 0;
	m.e[0][3] = 0;
	m.e[1][0] = 0;
	m.e[1][1] = 1;
	m.e[1][2] = 0;
	m.e[1][3] = 0;
	m.e[2][0] = 0;
	m.e[2][1] = 0;
	m.e[2][2] = 1;
	m.e[2][3] = 0;
	m.e[3][0] = 0;
	m.e[3][1] = 0;
	m.e[3][2] = 0;
	m.e[3][3] = 1;
	return (m);
}

/*	m -> Transformation matrix, q -> quaternion to rotate the bases,
	t -> translation part.
*/
static void	set_rot_matrix(t_matrix *m, t_quaternion *q)
{
	*m = matrix_identity();
	m->e[0][0] = 2 * (pow(q->w, 2) + pow(q->i, 2)) - 1;
	m->e[0][1] = 2 * (q->i * q->j - q->w * q->k);
	m->e[0][2] = 2 * (q->i * q->k + q->w * q->j);
	m->e[1][0] = 2 * (q->i * q->j + q->w * q->k);
	m->e[1][1] = 2 * (pow(q->w, 2) + pow(q->j, 2)) - 1;
	m->e[1][2] = 2 * (q->j * q->k - q->w * q->i);
	m->e[2][0] = 2 * (q->i * q->k - q->w * q->j);
	m->e[2][1] = 2 * (q->j * q->k + q->w * q->i);
	m->e[2][2] = 2 * (pow(q->w, 2) + pow(q->k, 2)) - 1;
}

static void	set_translation_matrix(t_matrix *m, t_point3 *t)
{
	*m = matrix_identity();
	m->e[0][3] = -get_x(t);
	m->e[1][3] = -get_y(t);
	m->e[2][3] = -get_z(t);
}

/* origin -> 0, 0, 0 ; face_direction -> (0, 0, 1) */
t_matrix	world_to_local(t_point3 *origin, t_vec3 *face_direction)
{
	t_matrix		rot_m;
	t_matrix		trans_m;
	t_quaternion	q;
	t_vec3			z;

	z = vec3(0, 0, 1);
	if (face_direction == NULL)
		face_direction = &z;
	q = get_quaternion(face_direction, &z);
	set_rot_matrix(&rot_m, &q);
	set_translation_matrix(&trans_m, origin);
	return (matrix_multiply(&rot_m, &trans_m));
}
