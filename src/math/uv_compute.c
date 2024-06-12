/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:26:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/12 17:09:59 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point2	compute_sphere_uv(t_hitrecord *hr)
{
	t_point3	lp;
	t_point2	uv;
	double		theta;
	double		phi;

	lp = unit_vector(apply_transform_to_point(\
		&hr->hit->shape.sp.wtl_matrix, &hr->at));
	theta = M_PI + atan2(get_y(&lp), get_x(&lp));
	phi = M_PI - acos(get_z(&lp) / vec3_length(&lp));
	uv.x = theta / (2 * M_PI);
	uv.y = phi / M_PI;
	return (uv);
}

t_point2	compute_plane_uv(t_hitrecord *hr)
{
	t_point3	p;
	t_vec3		x;
	t_vec3		y;
	t_point2	uv;

	x = vec3(1, 0, 0);
	y = vec3(0, 1, 0);
	p = apply_transform_to_point(&hr->hit->shape.pl.wtl_matrix, &hr->at);
	uv.x = (vec3_dot(&p, &x) + 1.0) / 2.0;
	uv.y = (vec3_dot(&p, &y) + 1.0) / 2.0;
	return (uv);
}
