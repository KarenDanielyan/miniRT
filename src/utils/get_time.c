/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:23:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 21:31:30 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <sys/time.h>

typedef struct timeval	t_time;

uint64_t	get_time(bool to_init)
{
	static t_time	init;
	t_time			current;
	uint64_t		rv;

	if (to_init)
		gettimeofday(&init, NULL);
	gettimeofday(&current, NULL);
	current.tv_sec -= init.tv_sec;
	current.tv_usec -= init.tv_usec;
	rv = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (rv);
}
