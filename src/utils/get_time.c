/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:23:32 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <sys/time.h>

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
