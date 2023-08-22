/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:03 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/19 17:42:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

void	*listen(void *control);
void	init_threads(t_control *ctl, int thread_count);
int		job_available(t_darray *jobs);

void	init_threadpool(t_control *ctl)
{
	int	i;

	pthread_mutex_init(&ctl->qmux, NULL);
	ctl->worker_c = 1; //sysconf(_SC_NPROCESSORS_ONLN) - 1;
	prompt_next_line(ctl, PLAIN_C, "");
	prompt_next_line(ctl, STATUS_C, "%d threads are available.", \
		ctl->worker_c);
	init_threads(ctl, ctl->worker_c);
	i = -1;
	while (++i < ctl->worker_c)
		pthread_create(ctl->pool[i].thread, NULL, &listen, &ctl->pool[i]);
}

void	*listen(void *thread)
{
	t_thread	*t;
	t_control	*ctl;
	int			index;

	t = (t_thread *)thread;
	ctl = t->ctl;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		index = job_available(&ctl->job_q);
		if (index >= 0)
			((t_job *)ctl->job_q.content)[index].taken = true;
		pthread_mutex_unlock(&ctl->qmux);
		if (index >= 0)
		{
			((t_job *)ctl->job_q.content)[index].job_func(ctl, &ctl->cam, \
				((t_job *)ctl->job_q.content) + index);
			usleep(1000);
			// mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, 
			// 	ctl->render.mlx_image, INFO_WIDTH, PREVIEW_HEIGHT);
		}
	}
	return (NULL);
}

void	init_threads(t_control *ctl, int thread_count)
{
	int	i;

	ctl->pool = (t_thread *)malloc(thread_count * sizeof(t_thread));
	if (!ctl->pool)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < thread_count)
	{
		ctl->pool[i].id = (i + 1);
		ctl->pool[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		ctl->pool[i].ctl = ctl;
		prompt_next_line(ctl, STATUS_C, "Worker [%d] initialized.", i);
		i ++;
	}
}

int	job_available(t_darray *jobs)
{
	size_t	i;

	i = 0;
	while (i < jobs->size)
	{
		if (((t_job *)jobs->content)[i].taken == false)
			return (i);
		i ++;
	}
	return (-1);
}
