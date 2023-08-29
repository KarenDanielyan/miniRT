/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:49:06 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/29 14:17:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static t_vec3	get_ray_dir(t_camera *cam, t_point3 pix_origin, int i, int j)
{
	t_vec3	dir;
	t_vec3	tmp;

	tmp = scale_vec3(i, &cam->pixel_delta_v);
	dir = sum_vec3(&pix_origin, &tmp);
	tmp = scale_vec3(j, &cam->pixel_delta_u);
	dir = sum_vec3(&dir, &tmp);
	dir = subst_vec3(&dir, &cam->origin);
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

void	graphical_hello_world(t_control *ctl, t_camera *cam)
{
	int			i;
	int			j;
	t_ray		r;

	i = 0;
	while (i < ctl->render.height)
	{
		j = 0;
		while (j < ctl->render.width)
		{
			new_ray(&r, cam->origin, get_ray_dir(cam, cam->pixel_origin, i, j));
			set_color(((ctl->render.data + i * ctl->render.width) + j), \
				ray_color(&r));
			j ++;
		}
		i ++;
		mlx_put_image_to_window(ctl->mlx_ptr, \
		ctl->win_ptr, ctl->render.mlx_image, 0, 0);
	}
}
