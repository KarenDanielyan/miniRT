/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/07 22:23:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "color.h"
#include <stdio.h>
#include <libft.h>

#define HEIGHT 360
#define WIDTH HEIGHT * ASPECT_RATIO

static void	graphical_hello_world(t_control *ctl, t_camera *cam);

static void	camera_setup(t_camera *cam)
{
	float	viewport_height;
	float	viewport_width;
	t_vec3	tmp;

	cam->focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = ASPECT_RATIO * viewport_height;

	cam->origin = vec3(0, 0, 0);
	cam->horizontal = vec3(viewport_width, 0, 0);
	cam->vertical = vec3(0, viewport_height, 0);
	tmp = shrink_vec3(2, &cam->horizontal);
	tmp = subst_vec3(&cam->origin, &tmp);
	cam->lower_left_corner = tmp;
	tmp = shrink_vec3(2, &cam->vertical);
	cam->lower_left_corner = subst_vec3(&cam->lower_left_corner, &tmp);
	tmp = vec3(0, 0, cam->focal_length);
	cam->lower_left_corner = subst_vec3(&cam->lower_left_corner, &tmp);
}

t_vec3	get_ray_dir(t_camera *cam, int i, int j)
{
	t_vec3	dir;
	t_vec3	tmp;
	float	u;
	float	v;

	u = (float )j/(WIDTH - 1);
	v = (float )i/(HEIGHT - 1);
	tmp = scale_vec3(u, &cam->horizontal);
	dir = sum_vec3(&cam->lower_left_corner, &tmp);
	tmp = scale_vec3(v, &cam->vertical);
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

int	main(int ac, char **av)
{
	t_control	ctl;
	t_camera	cam;

	if (ac != 2)
	{
		(void)av;
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	camera_setup(&cam);
	printf("%f\n", M_PI);
	ctl.mlx_ptr = mlx_init();
	ctl.win_ptr = mlx_new_window(ctl.mlx_ptr, WIDTH, HEIGHT, \
		"Graphical Hello World");
	graphical_hello_world(&ctl, &cam);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}

static void	graphical_hello_world(t_control *ctl, t_camera *cam)
{
	int		i;
	int		j;
	int		*line;
	t_ray	r;

	i = 0;
	new_image(ctl->mlx_ptr, WIDTH, HEIGHT, &ctl->image);
	while (i < HEIGHT)
	{
		j = 0;
		line = ctl->image.data + i * WIDTH;
		while (j < WIDTH)
		{
			new_ray(&r, cam->origin, get_ray_dir(cam, i, j));
			set_color((line + j), ray_color(&r));
			j ++;
		}
		i ++;
		usleep(5000);
		mlx_put_image_to_window(ctl->mlx_ptr, \
		ctl->win_ptr, ctl->image.mlx_image, 0, 0);
	}
}