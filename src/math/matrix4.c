/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:27:28 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 20:51:42 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "matrix4.h"

void	matrix44_new(t_matrix4	*self)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				self->e[i][j] = 1.0f;
			else
				self->e[i][j] = 0.0f;
			j ++;
		}
		i ++;
	}
}

void	matvec_mult(t_matrix4 *m, t_vec3 *vec, t_vec3 *result)
{
	set_x(result, (m->e[0][0] * get_x(vec) + m->e[0][1] * \
		get_y(vec) + m->e[0][2] * get_z(vec) + m->e[0][3]));
	set_y(result, (m->e[1][0] * get_x(vec) + m->e[1][1] * \
		get_y(vec) + m->e[1][2] * get_z(vec) + m->e[1][3]));
	set_z(result, (m->e[2][0] * get_x(vec) + m->e[2][1] * \
		get_y(vec) + m->e[2][2] * get_z(vec) + m->e[2][3]));
}

void	apply_rotation(t_matrix4 *m, t_vec3 *vec, t_vec3 *result)
{
	set_x(result, (m->e[0][0] * get_x(vec) + m->e[0][1] * \
		get_y(vec) + m->e[0][2] * get_z(vec)));
	set_y(result, (m->e[1][0] * get_x(vec) + m->e[1][1] * \
		get_y(vec) + m->e[1][2] * get_z(vec)));
	set_z(result, (m->e[2][0] * get_x(vec) + m->e[2][1] * \
		get_y(vec) + m->e[2][2] * get_z(vec)));
}
