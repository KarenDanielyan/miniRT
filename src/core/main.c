/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 21:12:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "debug.h"
#include "vec3.h"
#include "material.h"
#include "scanner.h"
#include <stdio.h>
#include <libft.h>

void		generate_tasks(t_control *ctl);
static void	env_init(t_control *ctl);
static void	create_world(t_darray *world);

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
int	main(int ac, char **av)
{
	t_control	ctl;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	env_init(&ctl);
	scan(&ctl, &ctl.world, av[1]);
	create_world(&ctl.world);
	generate_tasks(&ctl);
	run(&ctl);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}

static void	env_init(t_control *ctl)
{
	ctl->job_q = NULL;
	ctl->worker_c = sysconf(_SC_NPROCESSORS_ONLN) - 1;
	pthread_mutex_init(&ctl->qmux, NULL);
	init_ui(ctl);
}

static void	create_world(t_darray *world)
{
	void	*shape;
	void	*hittable;

	shape = new_sphere(vec3(0.0, -100.5, -1.0), 100);
	hittable = new_hittable(SPHERE, &hit_sphere, shape);
	((t_hittable *)hittable)->material.color = vec3(1, 0, 0);
	ft_darray_pushback(world, hittable);
	free(shape);
	free(hittable);
	shape = new_sphere(vec3(0.0, 0.0, -1.0), 0.5);
	hittable = new_hittable(SPHERE, &hit_sphere, shape);
	((t_hittable *)hittable)->material.color = vec3(1, 1, 0);
	ft_darray_pushback(world, hittable);
	free(shape);
	free(hittable);
}
