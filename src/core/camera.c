/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:40:17 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/09 19:29:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "camera.h"
#include "matrix4.h"
#include <math.h>

void	set_canvas_dimensions(t_camera *cam);

void	initialize_camera(t_camera *cam)
{
	t_point3	viewport_upperleft;
	t_point3	temp;

	look_at(&cam->center, &cam->direction, &cam->camera_to_world);
	set_canvas_dimensions(cam);
	temp = vec3_neg(&cam->direction);
	temp = scale_vec3(cam->focal_length, &temp);
	viewport_upperleft = subst_vec3(&cam->center, &temp);
	temp = shrink_vec3(2.0f, &cam->viewport_u);
	viewport_upperleft = subst_vec3(&viewport_upperleft, &temp);
	temp = shrink_vec3(2.0f, &cam->viewport_v);
	viewport_upperleft = subst_vec3(&viewport_upperleft, &temp);
	temp = sum_vec3(&cam->pixel_delta_u, &cam->pixel_delta_v);
	temp = shrink_vec3(2.0f, &temp);
	cam->pixel_00 = sum_vec3(&viewport_upperleft, &temp);
}

void	set_canvas_dimensions(t_camera *cam)
{
	float	aspect_ratio;
	float	viewport_width;
	float	viewport_height;
	t_vec3	tmp;

	aspect_ratio = (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT;
	cam->focal_length = FOCAL_LENGTH;
	viewport_width = 2 * tan((cam->h_fov * M_PI) / 360) * cam->focal_length;
	new_vec3(&tmp, viewport_width, 0, 0);
	apply_rotation(&cam->camera_to_world, &tmp, &cam->viewport_u);
	viewport_height = viewport_width / aspect_ratio;
	new_vec3(&tmp, 0, -viewport_height, 0);
	apply_rotation(&cam->camera_to_world, &tmp, &cam->viewport_v);
	cam->pixel_delta_u = shrink_vec3((float)IMAGE_WIDTH, &cam->viewport_u);
	cam->pixel_delta_v = shrink_vec3((float)IMAGE_HEIGHT, &cam->viewport_v);
}

/* TODO: Add boundary conditions check: direction == v_up etc. */
void	look_at(t_point3 *origin, t_vec3 *direction, t_matrix4 *T)
{
	t_vec3	v_up;
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;

	v_up = vec3(0.0, 1.0, 0.0);
	forward = vec3_neg(direction);
	vec3_normalize(&forward);
	right = vec3_cross(&v_up, &forward);
	up = vec3_cross(&forward, &right);
	matrix44_new(T);
	T->e[0][0] = get_x(&right);
	T->e[0][1] = get_y(&right);
	T->e[0][2] = get_z(&right);
	T->e[0][3] = get_x(origin);
	T->e[1][0] = get_x(&up);
	T->e[1][1] = get_y(&up);
	T->e[1][2] = get_z(&up);
	T->e[1][3] = get_y(origin);
	T->e[2][0] = get_x(&forward);
	T->e[2][1] = get_y(&forward);
	T->e[2][2] = get_z(&forward);
	T->e[2][3] = get_z(origin);
}

void	render(t_control *ctl, t_job *job)
{
	int			i;
	int			j;
	t_point2	loc;

	i = (int)(job->from.y);
	while (i < (int)(job->to.y))
	{
		j = (int)(job->from.x);
		while (j < (int)(job->to.x))
		{
			loc.y = i;
			loc.x = j;
			job->shader(ctl, &loc);
			j ++;
		}
		i ++;
	}
}
