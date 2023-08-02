/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:09:15 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 17:18:43 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	printf_putstr_fd(int fd, char *str)
{
	int	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			write(fd, str++, 1);
			count ++;
		}
	}
	else
	{
		count = 6;
		write(fd, "(null)", 6);
	}
	return (count);
}
