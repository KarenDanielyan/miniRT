/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:31:01 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/06 22:10:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>
#include <math.h>

#define CROP_SCALE 50

static void	get_crops(t_darray *crops, t_image *r, int crop_c);
t_job		*new_job(t_task *task, t_compute shader);

void	generate_tasks(t_control *ctl)
{
	t_image		*img;
	t_darray	tasks;
	size_t		i;
	int			crop_c;

	img = &ctl->render;
	crop_c = CROP_SCALE * ctl->worker_c;
	get_crops(&tasks, img, crop_c);
	i = 0;
	pthread_mutex_lock(&ctl->qmux);
	while (i < tasks.nmemb)
	{
		ft_lstadd_back(&ctl->job_q, \
			ft_lstnew(new_job(((t_task *)(tasks.content) + i), &ray_shader)));
		i ++;
	}
	pthread_mutex_unlock(&ctl->qmux);
	ft_darray_free(&tasks, NULL);
}

t_job	*new_job(t_task *task, t_compute shader)
{
	t_job	*job;

	job = (t_job *)ft_calloc(1, sizeof(t_job));
	if (!job)
		exit(EXIT_FAILURE);
	job->busy = false;
	job->from.x = task->from.x;
	job->from.y = task->from.y;
	job->to.x = task->to.x;
	job->to.y = task->to.y;
	job->shader = shader;
	return (job);
}

static void	crop(t_darray *crops, t_image *r, t_point *delta, int cut_count)
{
	t_task	current;
	int		i;
	int		j;

	i = 0;
	while (i < cut_count)
	{
		j = 0;
		while (j < cut_count)
		{
			current.from.x = i * delta->u;
			current.from.y = j * delta->v;
			current.to.x = (i + 1) * delta->u;
			current.to.y = (j + 1) * delta->v;
			if (i == cut_count - 1)
				current.to.x = r->width;
			if (j == cut_count - 1)
				current.to.y = r->height;
			ft_darray_pushback(crops, &current);
			j ++;
		}
		i ++;
	}
}

static void	get_crops(t_darray *crops, t_image *r, int crop_c)
{
	t_point	delta;
	int		cut_count;

	ft_darray_init(crops, sizeof(t_task), crop_c);
	cut_count = floor(sqrt(crop_c));
	delta.u = r->width / cut_count;
	delta.v = r->height / cut_count;
	if (delta.u < 1 && delta.v < 1)
		crop(crops, r, &delta, 1);
	else
		crop(crops, r, &delta, cut_count);
}
