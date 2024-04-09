/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:40:45 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/09 20:51:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"
#include "camera.h"

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

t_color	ray_color(t_ray *ray)
{
	t_color	c;
	t_vec3	uv;
	float	a;

	uv = unit_vector(ray->direction);
	a = 0.5 * (get_y(&uv) + 1.0);
	c = vec3(1.0, 1.0, 1.0);
	uv = vec3(0.5, 0.7, 1.0);
	c = scale_vec3((1 - a), &c);
	uv = scale_vec3(a, &uv);
	c = sum_vec3(&c, &uv);
	return (c);
}

void	ray_shader(t_control *ctl, t_point2 *loc)
{
	t_ray	r;
	int		i;
	int		j;

	i = (int)loc->y;
	j = (int)loc->x;
	new_ray(&r, ctl->cam.center, \
		get_ray_dir(&ctl->cam, ctl->cam.pixel_00, i, j));
	set_color(get_pixel(ctl, loc->y, loc->x), ray_color(&r));
}
