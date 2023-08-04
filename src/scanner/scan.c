/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/04 20:46:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>
#include <unistd.h>

static void	scan_prime(t_darray *arr, int fd);

char	scan(t_darray *arr, char *filename)
{
	int	fd;

	if (check_extension(filename) == EXIT_SUCCESS)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			printf(ERROR_MSG);
			return (EXIT_FAILURE);
		}
		scan_prime(arr, fd);
	}
	return (EXIT_SUCCESS);
}

static void	scan_prime(t_darray *arr, int fd)
{
	char	*str;
	void	*content;

	str = NULL;
	ft_darray_init(arr, sizeof(t_object), 100);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		content = parse_object(str);
		if (!content)
		{
			printf(ERROR_MSG);
			break ;
		}
		ft_darray_pushback(arr, content);
	}
}
