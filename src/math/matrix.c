/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:46:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 21:44:50 by kdaniely         ###   ########.fr       */
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
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	*m = matrix_identity();
	x = vec3(1, 0, 0);
	y = vec3(0, 1, 0);
	z = vec3(0, 0, 1);
	x = quarternion_rotate(q, &x);
	y = quarternion_rotate(q, &y);
	z = quarternion_rotate(q, &z);
	m->e[0][0] = get_x(&x);
	m->e[0][1] = get_x(&y);
	m->e[0][2] = get_x(&z);
	m->e[1][0] = get_y(&x);
	m->e[1][1] = get_y(&y);
	m->e[1][2] = get_y(&z);
	m->e[2][0] = get_z(&x);
	m->e[2][1] = get_z(&y);
	m->e[2][2] = get_z(&z);
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
