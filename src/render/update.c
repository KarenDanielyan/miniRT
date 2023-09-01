/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:50:23 by kdaniely          #+#    #+#             */
/*   Updated: 2023/09/01 18:53:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <string.h>
#include <stdio.h>

int	job_available(void *j);

void	update(t_control *ctl)
{
	int	cur_avail;
	int	prev_avail;
	int	tmp;
	int	done;

	prev_avail = 0;
	done = 0;
	while (1)
	{
		pthread_mutex_lock(&ctl->qmux);
		cur_avail = ft_lstcountif(ctl->job_q, &job_available);
		tmp = ft_lstsize(ctl->job_q);
		done = ((tmp - cur_avail) * 100 / tmp);
		pthread_mutex_unlock(&ctl->qmux);
		if (cur_avail == 0)
			break ;
		if (cur_avail != prev_avail)
		{
			print_bar(ctl, done);
			put_render(ctl);
		}
		prev_avail = cur_avail;
	}
	print_bar(ctl, 100);
	prompt_next_line(ctl, 0, "");
}

int	job_available(void *j)
{
	t_job	*job;

	job = (t_job *)j;
	if (job->busy == true)
		return (false);
	else
		return (true);
}
