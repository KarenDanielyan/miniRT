/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:43 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 22:34:29 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "scanner.h"
#include "shapes.h"

static void	scan_prime(t_control *ctl, t_darray *arr, int fd);

char	scan(t_control *ctl, t_darray *arr, char *filename)
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
		scan_prime(ctl, arr, fd);
	}
	return (EXIT_SUCCESS);
}

static void	scan_prime(t_control *ctl, t_darray *arr, int fd)
{
	char	*str;
	void	*content;

	str = NULL;
	ft_darray_init(arr, sizeof(t_hittable), 5);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		content = parse_object(ctl, str);
		if (!content && str[0] != 'C')
		{
			printf(ERROR_MSG);
			free(str);
			break ;
		}
		if (content)
			ft_darray_pushback(arr, content);
		free(content);
		free(str);
	}
}

void	*parse_object(t_control *ctl, char *line)
{
	char		**splitted;
	void		*rv;

	rv = NULL;
	splitted = ft_split(line, ' ');
	if (!ft_strcmp(splitted[0], "A"))
		printf("A");//TODO:
	else if (!ft_strcmp(splitted[0], "C"))
		rv = parse_camera(ctl, splitted);
	else if (!ft_strcmp(splitted[0], "L"))
		printf("L");//TODO:
	else if (!ft_strcmp(splitted[0], "pl"))
		printf("pl");//TODO:
	else if (!ft_strcmp(splitted[0], "sp"))
		printf("sp");//TODO:
	else if (!ft_strcmp(splitted[0], "cy"))
		printf("cy");//TODO:
	else
		printf("Bad argument:");
	free_2d(splitted);
	return (rv);
}
