/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/08 14:54:22 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "color.h"
#include <stdio.h>
#include <libft.h>

static void	graphical_hello_world(t_control *ctl, t_camera *cam, int w, int h);

static void	camera_setup(t_camera *cam, int image_width, int image_height)
{
	float	viewport_height;
	float	viewport_width;
	t_vec3	tmp;

	cam->focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * (float)(image_width / image_height);
	cam->origin = vec3(0, 0, 0);
	cam->viewport_u = vec3(viewport_width, 0, 0);
	cam->viewport_v = vec3(0, -viewport_height, 0);
	cam->pixel_delta_u = shrink_vec3(image_width, &cam->viewport_u);
	cam->pixel_delta_v = shrink_vec3(image_height, &cam->viewport_v);
	tmp = vec3(0, 0, cam->focal_length);
	cam->upper_left = subst_vec3(&cam->origin, &tmp);
	tmp = shrink_vec3(2, &cam->viewport_u);
	cam->upper_left = subst_vec3(&cam->upper_left, &tmp);
	tmp = shrink_vec3(2, &cam->viewport_v);
	cam->upper_left = subst_vec3(&cam->upper_left, &tmp);
}

t_vec3	get_ray_dir(t_camera *cam, t_point pix_origin, int i, int j)
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

t_color	ray_color(t_ray *ray)
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

int	main(void)
{
	t_control	ctl;
	t_camera	cam;
	int			width;
	int			height;

	width = 640;
	height = (int)(width / ((float)ASPECT_RATIO));
	if (height < 1)
		height = 1;
	camera_setup(&cam, width, height);
	printf("%f\n", M_PI);
	ctl.mlx_ptr = mlx_init();
	ctl.win_ptr = mlx_new_window(ctl.mlx_ptr, width, height, \
		"Graphical Hello World");
	graphical_hello_world(&ctl, &cam, width, height);
	create_image("render.ppm", ctl.image.data, ctl.image.width, \
		ctl.image.height);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}

static void	graphical_hello_world(t_control *ctl, t_camera *cam, int w, int h)
{
	int		i;
	int		j;
	t_ray	r;
	t_point	pix_origin;

	i = 0;
	pix_origin = sum_vec3(&cam->pixel_delta_u, &cam->pixel_delta_v);
	pix_origin = shrink_vec3(2, &pix_origin);
	pix_origin = sum_vec3(&cam->upper_left, &pix_origin);
	new_image(ctl->mlx_ptr, w, h, &ctl->image);
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			new_ray(&r, cam->origin, get_ray_dir(cam, pix_origin, i, j));
			set_color(((ctl->image.data + i * w) + j), ray_color(&r));
			j ++;
		}
		i ++;
		usleep(2000);
		mlx_put_image_to_window(ctl->mlx_ptr, \
		ctl->win_ptr, ctl->image.mlx_image, 0, 0);
	}
}
