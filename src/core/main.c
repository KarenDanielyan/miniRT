/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 00:59:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "material.h"
#include "scanner.h"
#include <stdio.h>
#include <libft.h>

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
int	main(int ac, char **av)
{
	t_control	ctl;

	if (ac != 2)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	env_init(&ctl);
	if (scan(&ctl, av[1]) == EXIT_FAILURE)
	{
		mlx_destroy_window(ctl.mlx_ptr, ctl.win_ptr);
		exit(EXIT_FAILURE);
	}
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
