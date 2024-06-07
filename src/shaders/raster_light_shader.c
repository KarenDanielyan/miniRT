/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster_light_shader.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:34:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/03 02:38:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "quaternion.h"

void	render_light(t_control *ctl, t_light *l)
{
	t_matrix	wtc;
	t_point3	p;
	t_point		pixel;

	wtc = world_to_local(&ctl->cam.center, &ctl->cam.direction);
	p = apply_transform_to_point(&wtc, &l->position);
	set_x(&p, get_x(&p) / -get_z(&p));
	set_y(&p, get_y(&p) / -get_z(&p));
	set_x(&p, \
		(get_x(&p) + ctl->cam.canvas_width / 2.0f) / ctl->cam.canvas_width);
	set_y(&p, \
		(get_y(&p) + ctl->cam.canvas_height / 2.0f) / ctl->cam.canvas_height);
	pixel.u = (int)(get_x(&p) * IMAGE_WIDTH);
	pixel.v = (int)(get_y(&p) * IMAGE_HEIGHT);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->light_icon.mlx_image, pixel.u, pixel.v);
}

void	cast_and_render(t_control *ctl, t_light *l)
{
	t_ray		r;
	t_vec3		delta;
	t_vec3		delta_obj;
	t_hitrecord	hr;

	delta = subst_vec3(&l->position, &ctl->cam.center);
	r.origin = ctl->cam.center;
	r.direction = unit_vector(delta);
	if (vec3_dot(&r.direction, &ctl->cam.direction) > 0.0)
	{
		if (hit_anything(&r, &ctl->world, &hr) == false)
		{
			render_light(ctl, l);
			return ;
		}
		delta_obj = subst_vec3(&hr.at, &ctl->cam.center);
		if (vec3_length(&delta) < vec3_length(&delta_obj))
			render_light(ctl, l);
	}
}

void	raster_light_sources(t_control *ctl)
{
	size_t		i;
	t_light		*light;

	i = 0;
	while (i < ctl->lights.nmemb)
	{
		light = ft_darray_get_by_index(&ctl->lights, i);
		if (light->type == POINT)
			cast_and_render(ctl, light);
		i ++;
	}
}
