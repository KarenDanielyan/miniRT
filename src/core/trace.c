/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:33:34 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/21 01:44:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

static t_color	super_sample(t_control *ctl, t_job *job, int i, int j);
static t_vec3	get_ray(t_camera *cam, uint32_t *rng_state, int i, int j);

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

static t_vec3	get_ray(t_camera *cam, uint32_t *rng_state, int i, int j)
{
	t_vec3		dir;
	t_vec3		tmp;
	t_point2	box;

	box.x = 0;
	box.y = 0;
	if (SSAA > 1)
	{
		box.x = random_value(rng_state) - 0.5;
		box.y = random_value(rng_state) - 0.5;
	}
	tmp = scale_vec3((i + box.y), &cam->pixel_delta_v);
	dir = sum_vec3(&cam->pixel_00, &tmp);
	tmp = scale_vec3((j + box.x), &cam->pixel_delta_u);
	dir = sum_vec3(&dir, &tmp);
	dir = subst_vec3(&dir, &cam->center);
	return (dir);
}

static t_color	super_sample(t_control *ctl, t_job *job, int i, int j)
{
	t_color		color;
	t_color		new_color;
	t_ray		r;
	int			k;

	k = 1;
	new_ray(&r, ctl->cam.center, get_ray(&ctl->cam, &ctl->rng_state, i, j));
	color = job->shader(ctl, &r, MAX_BOUNCE);
	while (k < SSAA)
	{
		new_ray(&r, ctl->cam.center, get_ray(&ctl->cam, &ctl->rng_state, i, j));
		new_color = job->shader(ctl, &r, MAX_BOUNCE);
		color = sum_vec3(&color, &new_color);
		k ++;
	}
	return (shrink_vec3((float)SSAA, &color));
}
