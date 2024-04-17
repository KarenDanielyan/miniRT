/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:09:39 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/15 20:45:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

static void	create_pool(t_control *ctl);
static void	cleanup(t_control *ctl);
void		update(t_control *ctl);
void		*listen(void *control);

void	run(t_control *ctl)
{
	get_time(true);
	ft_printf("\033[34m%d workers are available.\n\033[0m", \
		ctl->worker_c);
	create_pool(ctl);
	update(ctl);
	cleanup(ctl);
	ft_printf("\033[34mRendering finished after %ldms.\n\033[0m", \
		get_time(false));
	put_render(ctl);
}

static void	create_pool(t_control *ctl)
{
	int	i;

	ctl->pool = (t_thread *)malloc(ctl->worker_c * sizeof(t_thread));
	if (!ctl->pool)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < ctl->worker_c)
	{
		ctl->pool[i].id = (i + 1);
		ctl->pool[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		ctl->pool[i].ctl = ctl;
		ft_printf("\033[34mWorker [%d] initialized.\n\033[0m", i);
	}
	i = -1;
	while (++i < ctl->worker_c)
		pthread_create(ctl->pool[i].thread, NULL, &listen, &ctl->pool[i]);
}

static void	cleanup(t_control *ctl)
{
	int	i;

	i = -1;
	while (++i < ctl->worker_c)
		pthread_join(*ctl->pool[i].thread, NULL);
}
