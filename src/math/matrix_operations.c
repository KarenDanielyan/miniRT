/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:36:51 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 21:39:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_multiply(t_matrix *a, t_matrix *b)
{
	t_matrix	m;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.e[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				m.e[i][j] += a->e[i][k] * b->e[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (m);
}

t_vec3	apply_transform_to_vector(t_matrix *m, t_vec3 *v)
{
	t_vec3	result;

	set_x(&result, \
		m->e[0][0] * get_x(v) + m->e[0][1] * get_y(v) + m->e[0][2] * get_z(v));
	set_y(&result, \
		m->e[1][0] * get_x(v) + m->e[1][1] * get_y(v) + m->e[1][2] * get_z(v));
	set_z(&result, \
		m->e[2][0] * get_x(v) + m->e[2][1] * get_y(v) + m->e[2][2] * get_z(v));
	return (result);
}

/* Column-major order matrix */
t_point3	apply_transform_to_point(t_matrix *m, t_point3 *p)
{
	t_vec3	result;

	set_x(&result, \
		m->e[0][0] * get_x(p) + m->e[0][1] * get_y(p) + m->e[0][2] * get_z(p) \
		+ m->e[0][3]);
	set_y(&result, \
		m->e[1][0] * get_x(p) + m->e[1][1] * get_y(p) + m->e[1][2] * get_z(p) \
		+ m->e[1][3]);
	set_z(&result, \
		m->e[2][0] * get_x(p) + m->e[2][1] * get_y(p) + m->e[2][2] * get_z(p) \
		+ m->e[2][3]);
	return (result);
}
