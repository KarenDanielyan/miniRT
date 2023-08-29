/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:11:04 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/29 21:53:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_tasks(t_control *ctl)
{
	t_list		*head;
	t_point2	*from;
	t_point2	*to;
	int			i;

	head = ctl->job_q;
	i = 0;
	while (head)
	{
		from = &((t_job *)head->content)->from;
		to = &((t_job *)head->content)->to;
		ft_printf("Task \033[35m[%d]\033[0m: x: \033[36m%d -> %d\033[0m     \
y: \033[36m%d -> %d\033[0m\n", i + 1, \
			(int)from->x, (int)to->x, (int)from->y, (int)to->y);
		head = head->next;
		i ++;
	}
}
