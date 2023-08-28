/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/26 20:05:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "color.h"
#include <stdio.h>
#include <libft.h>

void	graphical_hello_world(t_control *ctl, t_camera *cam);
void	camera_setup(t_camera *cam, int image_width, int image_height);

/**
 * Main logic:
 * 1. check file validity
 * 2. parse the file and generate world from it
 * 3. setup screen dimensions. make the screen.
 * 4. initialize job queue.
 * 5. Turn on renderer.
 * 6. Prompt the result on the screen.
 * 7. If you wish, you can save the render via tapping the button `S`.
 *    NOTE: You can only save it once.
 * 8. Event handlers at the end.
*/
int	main(void)
{
	t_control	ctl;
	t_camera	cam;

	init_ui(&ctl);
	camera_setup(&cam, ctl.win_u, ctl.win_v);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
	graphical_hello_world(&ctl, &cam);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}

void	camera_setup(t_camera *cam, int image_width, int image_height)
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
	cam->pixel_origin = sum_vec3(&cam->pixel_delta_u, &cam->pixel_delta_v);
	cam->pixel_origin = shrink_vec3(2, &cam->pixel_origin);
	cam->pixel_origin = sum_vec3(&cam->upper_left, &cam->pixel_origin);
}

t_vec3	get_ray_dir(t_camera *cam, t_point3 pix_origin, int i, int j)
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
		usleep(5000);
		mlx_put_image_to_window(ctl->mlx_ptr, \
		ctl->win_ptr, ctl->render.mlx_image, INFO_WIDTH + PREVIEW_OFFSET, \
			PREVIEW_HEIGHT + PREVIEW_OFFSET);
	}
}
