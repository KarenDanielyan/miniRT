/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:40:17 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 16:13:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <math.h>
#include "quaternion.h"

static t_color	super_sample(t_control *ctl, t_job *job, int i, int j);
static t_vec3	get_ray(t_camera *cam, int i, int j);

static void		set_canvas_dimensions(t_camera *cam);

void	initialize_camera(t_camera *cam)
{
	t_point3	viewport_upperleft;
	t_point3	temp;

	vec3_normalize(&cam->direction);
	set_canvas_dimensions(cam);
	temp = scale_vec3(cam->focal_length, &cam->direction);
	viewport_upperleft = sum_vec3(&cam->center, &temp);
	temp = shrink_vec3(2.0f, &cam->viewport_u);
	viewport_upperleft = subst_vec3(&viewport_upperleft, &temp);
	temp = shrink_vec3(2.0f, &cam->viewport_v);
	viewport_upperleft = subst_vec3(&viewport_upperleft, &temp);
	temp = sum_vec3(&cam->pixel_delta_u, &cam->pixel_delta_v);
	temp = shrink_vec3(2.0f, &temp);
	cam->pixel_00 = sum_vec3(&viewport_upperleft, &temp);
}

void	trace(t_control *ctl, t_job *job)
{
	int			i;
	int			j;
	t_color		color;

	i = (int)(job->from.y);
	while (i < (int)(job->to.y))
	{
		j = (int)(job->from.x);
		while (j < (int)(job->to.x))
		{
			color = super_sample(ctl, job, i, j);
			set_color(get_pixel(ctl, i, j), color);
			j ++;
		}
		i ++;
	}
}

static void	set_canvas_dimensions(t_camera *cam)
{
	float			viewport_width;
	float			viewport_height;
	t_quaternion	q;
	t_vec3			z_i;

	cam->focal_length = FOCAL_LENGTH;
	viewport_width = 2 * tan((cam->h_fov * M_PI) / 360) * cam->focal_length;
	viewport_height = viewport_width / \
		((float)IMAGE_WIDTH / (float)IMAGE_HEIGHT);
	cam->viewport_u = vec3(viewport_width, 0, 0);
	cam->viewport_v = vec3(0, -viewport_height, 0);
	cam->pixel_delta_u = shrink_vec3((float)IMAGE_WIDTH, &cam->viewport_u);
	cam->pixel_delta_v = shrink_vec3((float)IMAGE_HEIGHT, &cam->viewport_v);
	z_i = vec3(0, 0, -1);
	q = get_quaternion(&z_i, &cam->direction);
	cam->pixel_delta_u = quarternion_rotate(&q, &cam->pixel_delta_u);
	cam->pixel_delta_v = quarternion_rotate(&q, &cam->pixel_delta_v);
	cam->viewport_u = quarternion_rotate(&q, &cam->viewport_u);
	cam->viewport_v = quarternion_rotate(&q, &cam->viewport_v);
}

static t_vec3	get_ray(t_camera *cam, int i, int j)
{
	t_vec3		dir;
	t_vec3		tmp;
	t_point2	box;

	box.x = 0;
	box.y = 0;
	if (SSAA > 1)
	{
		box.x = ft_random_float() - 0.5;
		box.y = ft_random_float() - 0.5;
	}
	tmp = scale_vec3((i + box.y), &cam->pixel_delta_v);
	dir = sum_vec3(&cam->pixel_00, &tmp);
	tmp = scale_vec3((j + box.x), &cam->pixel_delta_u);
	dir = sum_vec3(&dir, &tmp);
	dir = subst_vec3(&dir, &cam->center);
	vec3_normalize(&dir);
	return (dir);
}

static t_color	super_sample(t_control *ctl, t_job *job, int i, int j)
{
	t_color		color;
	t_color		new_color;
	t_ray		r;
	int			k;

	k = 1;
	new_ray(&r, ctl->cam.center, get_ray(&ctl->cam, i, j));
	color = job->shader(ctl, &r, MAX_BOUNCE);
	while (k < SSAA)
	{
		new_ray(&r, ctl->cam.center, get_ray(&ctl->cam, i, j));
		new_color = job->shader(ctl, &r, MAX_BOUNCE);
		color = sum_vec3(&color, &new_color);
		k ++;
	}
	color = shrink_vec3(SSAA, &color);
	color = linear_to_gamma(color);
	return (vec3(\
			clamp_d(get_x(&color), 0.000, 0.999), \
			clamp_d(get_y(&color), 0.000, 0.999), \
			clamp_d(get_z(&color), 0.000, 0.999)));
}
