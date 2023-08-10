/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 18:58:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

void	*listen(void *control);
void	init_threads(t_control *ctl, int thread_count);

void	init_threadpool(t_control *ctl)
{
	int	thread_count;
	int	i;

	pthread_mutex_init(&ctl->qmux, NULL);
	thread_count = sysconf(_SC_NPROCESSORS_ONLN);
	prompt_next_line(ctl, PLAIN_C, "");
	prompt_next_line(ctl, STATUS_C, "%d threads are available.", \
		thread_count - 1);
	init_threads(ctl, thread_count);
	i = -1;
	while (++i < (thread_count - 1))
		pthread_create(ctl->pool[i].thread, NULL, &listen, &ctl->pool[i]);
}

void	*listen(void *thread)
{
	t_thread	*t;
	t_control	*ctl;

	t = (t_thread *)thread;
	ctl = t->ctl;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		if (ctl->job_q.size != 0)
			printf("I got a job %d\n", t->id);
		else
			printf("I don't have a job %d\n", t->id);
		pthread_mutex_unlock(&ctl->qmux);
	}
	return (NULL);
}

void	init_threads(t_control *ctl, int thread_count)
{
	int	i;

	ctl->pool = (t_thread *)malloc((thread_count - 1) * sizeof(t_thread));
	if (!ctl->pool)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (thread_count - 1))
	{
		ctl->pool[i].id = (i + 1);
		ctl->pool[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		ctl->pool[i].ctl = ctl;
		prompt_next_line(ctl, STATUS_C, "Worker [%d] initialized.", i);
		i ++;
	}
}
