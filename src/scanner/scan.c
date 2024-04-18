/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 16:55:18 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "shapes.h"
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
	ft_darray_init(arr, sizeof(t_hittable), 100);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		content = parse_object(str);
		if (!content && str[0] != 'C')
		{
			printf(ERROR_MSG);
			break ;
		}
		ft_darray_pushback(arr, content);
		free(content);
	}
}

void	*parse_object(char *line)
{
	t_control	*ctl;
	char		**splitted;
	splitted = ft_split(line, ' ');

	if (ft_strcmp(splitted[0], "A"))
		//TODO:
	else if (ft_strcmp(splitted[0], "C"))
		parse_camera(splitted, &ctl);
	else if (ft_strcmp(splitted[0], "L"))
		//TODO:
	else if (ft_strcmp(splitted[0], "pl"))
		//TODO:
	else if (ft_strcmp(splitted[0], "sp"))
		//TODO:
	else if (ft_strcmp(splitted[0], "cy"))
		//TODO:
	else 
		printf("Bad argument:");
	return (NULL);
}
