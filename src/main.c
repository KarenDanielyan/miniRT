/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/04 20:46:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>

#define ERROR_MSG "Error\n"

int	main(int ac, char **av)
{
	long	thread_count;

	if (ac != 2)
	{
		(void)av;
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	thread_count = sysconf(_SC_NPROCESSORS_CONF);
	printf("Number of threads on the current platform: %ld\n", thread_count);
	return (0);
}
