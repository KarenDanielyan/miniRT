/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 22:50:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

static void	init_threads(t_control *ctl, int thread_count);
static void	update_screen(t_control *ctl);
static void	*listen(void *control);

void	workers_init(t_control *ctl)
{
	int	i;

	prompt_next_line(ctl, PLAIN_C, "");
	prompt_next_line(ctl, STATUS_C, "%d workers are available.", \
		ctl->worker_c);
	get_time(true);
	init_threads(ctl, ctl->worker_c);
	i = -1;
	while (++i < ctl->worker_c)
		pthread_create(ctl->pool[i].thread, NULL, &listen, &ctl->pool[i]);
	update_screen(ctl);
	i = -1;
	while (++i < ctl->worker_c)
		pthread_join(*(ctl->pool[i].thread), NULL);
	put_render(ctl);
	prompt_next_line(ctl, STATUS_C, "Total Rendering time: %ldms.", get_time(false));
}

static void	update_screen(t_control *ctl)
{
	int	current_size;
	int	previous_size;

	previous_size = 0;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		current_size = ft_lstsize(ctl->job_q);
		pthread_mutex_unlock(&ctl->qmux);
		if (current_size == 0)
			break ;
		if (current_size != previous_size)
			put_render(ctl);
		previous_size = current_size;
	}
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
		sleep(1);
	}
	prompt_next_line(ctl, STATUS_C, "Thread [%d] finished execution.", t->id);
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
		prompt_next_line(ctl, STATUS_C, "Worker [%d] initialized.", i);
	}
}
