/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:31:01 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/29 21:56:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "debug.h"
#include <stdio.h>

#define CROP_SCALE 4

typedef struct s_task
{
	t_point2	from;
	t_point2	to;
}	t_task;

static t_task	*get_crops(t_image *r, int crop_c);
t_job			*new_job(t_point2	*from, t_point2	*to, \
	t_handler handler, t_compute shader);

void	generate_tasks(t_control *ctl)
{
	t_image	*img;
	t_task	*tasks;
	int		crop_c;
	int		i;

	img = &ctl->render;
	crop_c = CROP_SCALE * ctl->worker_c;
	tasks = get_crops(img, crop_c);
	i = 0;
	while (i < crop_c)
	{
		ft_lstadd_back(&ctl->job_q, \
			ft_lstnew(new_job(&tasks[i].from, &tasks[i].to, \
			NULL, NULL)));
		i ++;
	}
	free(tasks);
	print_tasks(ctl);
}

t_job	*new_job(t_point2	*from, t_point2	*to, \
	t_handler handler, t_compute shader)
{
	t_job	*job;

	job = (t_job *)ft_calloc(1, sizeof(t_job));
	if (!job)
		exit(EXIT_FAILURE);
	job->from.x = from->x;
	job->from.y = from->y;
	job->to.x = to->x;
	job->to.y = to->y;
	job->job_func = handler;
	job->shader = shader;
	return (job);
}

static	t_task	*get_crops(t_image *r, int crop_c)
{
	t_task	*crops;
	int		delta_u;
	int		delta_v;
	int		i;

	delta_u = r->width / crop_c;
	delta_v = r->height / crop_c;
	printf("Image Deltas %d <-> %d\n", delta_u, delta_v);
	i = 0;
	crops = (t_task *)malloc(crop_c * sizeof(t_task));
	while (i < crop_c)
	{
		crops[i].from.x = i * delta_u;
		crops[i].from.y = i * delta_v;
		crops[i].to.x = (i + 1) * delta_u - 1;
		crops[i].to.y = (i + 1) * delta_v - 1;
		i ++;
	}
	return (crops);
}
