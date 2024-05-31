/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:46:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 17:54:25 by kdaniely         ###   ########.fr       */
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

/* t_matrix	world_to_local(t_point3 obj, t_vec3 face_direction)
{
	t_matrix		m;
	t_quaternion	q;
	t_vec3			z;
	t_vec3			tmp_basis;

	z = vec3(0, 0, 1);
	q = get_quaternion(&z, &face_direction);
	tmp_basis = vec3(1, 0, 0);
	tmp_basis = quarternion_rotate(&q, &tmp_basis);
	m.e[0] = {get_x(&tmp_basis), get_y(&tmp_basis), get_z(&tmp_basis), 0};
}*/