/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 21:41:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

static void	init_threads(t_control *ctl, int thread_count);
static void	*listen(void *control);

void	workers_init(t_control *ctl)
{
	int	i;

	prompt_next_line(ctl, PLAIN_C, "");
	prompt_next_line(ctl, STATUS_C, "%d workers are available.\n", \
		ctl->worker_c);
	get_time(true);
	init_threads(ctl, ctl->worker_c);
	i = -1;
	while (++i < ctl->worker_c)
		pthread_create(ctl->pool[i].thread, NULL, &listen, &ctl->pool[i]);
	i = -1;
	while (++i < ctl->worker_c)
		pthread_join(*(ctl->pool[i].thread), NULL);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->render.mlx_image, INFO_WIDTH, PREVIEW_HEIGHT);
	prompt_next_line(ctl, 0, "Total Rendering time: %ldms.\n", get_time(false));
}

static void	*listen(void *thread)
{
	t_thread	*t;
	t_control	*ctl;
	t_job		*job;

	t = (t_thread *)thread;
	ctl = t->ctl;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		job = NULL;
		if (ctl->job_q)
		{
			job = (t_job *)ctl->job_q->content;
			ft_lstpop(&ctl->job_q, ctl->job_q, NULL);
		}
		pthread_mutex_unlock(&ctl->qmux);
		if (!job)
			break ;
		job->job_func(ctl, job);
		free(job);
	}
	prompt_next_line(ctl, 0, "Thread [%d] finished execution after %ldms.\n", \
		t->id, get_time(false));
	return (NULL);
}

static void	init_threads(t_control *ctl, int thread_count)
{
	int	i;

	ctl->pool = (t_thread *)malloc(thread_count * sizeof(t_thread));
	if (!ctl->pool)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < thread_count)
	{
		ctl->pool[i].id = (i + 1);
		ctl->pool[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		ctl->pool[i].ctl = ctl;
		prompt_next_line(ctl, STATUS_C, "Worker [%d] initialized.\n", i);
	}
}
