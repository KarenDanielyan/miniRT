/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:49:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/01 17:21:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <unistd.h>

static t_vec3	get_ray_dir(t_camera *cam, t_point3 pix_origin, int i, int j)
{
	t_vec3	dir;
	t_vec3	tmp;

	tmp = scale_vec3(i, &cam->pixel_delta_v);
	dir = sum_vec3(&pix_origin, &tmp);
	tmp = scale_vec3(j, &cam->pixel_delta_u);
	dir = sum_vec3(&dir, &tmp);
	dir = subst_vec3(&dir, &cam->center);
	return (dir);
}

static t_color	ray_color(t_ray *ray)
{
	t_color	start;
	t_color	end;
	t_color	blend;
	float	t;

	t = 0.5 * (get_y(&ray->direction) + 1.0);
	start = vec3(1.0, 1.0, 1.0);
	start = scale_vec3((1 - t), &start);
	end = vec3(0.5, 0.7, 1.0);
	end = scale_vec3(t, &end);
	blend = sum_vec3(&start, &end);
	return (blend);
}

void	basic_shader(t_control *ctl, t_point2 *loc, int *pixel)
{
	t_ray	r;
	int		i;
	int		j;

	i = (int)loc->y;
	j = (int)loc->x;
	new_ray(&r, ctl->cam.center, \
		get_ray_dir(&ctl->cam, ctl->cam.pixel_00, i, j));
	set_color(pixel, ray_color(&r));
}

void	graphical_hello_world(t_control *ctl, t_job *job)
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
			job->shader(ctl, &loc, \
				((ctl->render.data + i * ctl->render.width) + j));
			j ++;
		}
		i ++;
	}
}
