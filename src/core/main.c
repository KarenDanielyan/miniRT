/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 21:46:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "color.h"
#include <stdio.h>
#include <libft.h>

void		camera_setup(t_camera *cam, int image_width, int image_height);
void		generate_tasks(t_control *ctl);
static void	env_init(t_control *ctl);

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

	env_init(&ctl);
	generate_tasks(&ctl);
	camera_setup(&ctl.cam, ctl.win_u, ctl.win_v);
	workers_init(&ctl);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
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

static void	env_init(t_control *ctl)
{
	ctl->worker_c = sysconf(_SC_NPROCESSORS_ONLN) - 1;
	pthread_mutex_init(&ctl->qmux, NULL);
	pthread_mutex_init(&ctl->winmux, NULL);
	pthread_mutex_init(&ctl->pmux, NULL);
	init_ui(ctl);
}
