/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:50:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/31 20:08:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

void	*listen(void *thread)
{
	t_thread	*t;
	t_control	*ctl;
	t_list		*tmp;
	t_job		*job;

	t = (t_thread *)thread;
	ctl = t->ctl;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		tmp = ctl->job_q;
		while (tmp && ((t_job *)(tmp->content))->busy == true)
			tmp = tmp->next;
		if (tmp)
			((t_job *)(tmp->content))->busy = true;
		pthread_mutex_unlock(&ctl->qmux);
		if (!tmp)
			break ;
		job = tmp->content;
		job->job_func(ctl, job);
	}
	return (NULL);
}
