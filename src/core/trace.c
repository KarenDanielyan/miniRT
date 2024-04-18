/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:33:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec3	get_ray_dir(t_camera *cam, int i, int j);

void	trace(t_control *ctl, t_job *job)
{
	int			i;
	int			j;
	t_ray		r;
	t_color		color;

	i = (int)(job->from.y);
	while (i < (int)(job->to.y))
	{
		j = (int)(job->from.x);
		while (j < (int)(job->to.x))
		{
			new_ray(&r, ctl->cam.center, get_ray_dir(&ctl->cam, i, j));
			color = job->shader(ctl, &r);
			set_color(get_pixel(ctl, i, j), color);
			j ++;
		}
		i ++;
	}
}

static t_vec3	get_ray_dir(t_camera *cam, int i, int j)
{
	t_vec3	dir;
	t_vec3	tmp;

	tmp = scale_vec3(i, &cam->pixel_delta_v);
	dir = sum_vec3(&cam->pixel_00, &tmp);
	tmp = scale_vec3(j, &cam->pixel_delta_u);
	dir = sum_vec3(&dir, &tmp);
	dir = subst_vec3(&dir, &cam->center);
	return (dir);
}
