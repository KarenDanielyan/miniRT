/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:49:06 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/09 18:45:56 by kdaniely         ###   ########.fr       */
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
	vec3_normalize(&dir);
	return (dir);
}

static t_color	ray_color(t_ray *ray)
{
	// t_color	color;

	// if (get_x(&ray->direction) < 0.0f)
	// 	set_x(&color, 0.0f);
	// else
	// 	set_x(&color, get_x(&ray->direction));
	// if (get_y(&ray->direction) < 0.0f)
	// 	set_y(&color, 0.0f);
	// else
	// 	set_y(&color, get_y(&ray->direction));
	// if (get_z(&ray->direction) < 0.0f)
	// 	set_z(&color, 0.0f);
	// else
	// 	set_z(&color, get_z(&ray->direction));
	return (vec3(get_x(&ray->direction), get_x(&ray->direction), get_x(&ray->direction)));
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
