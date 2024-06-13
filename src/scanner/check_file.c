/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 22:26:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include <libft.h>

/**
 * @brief	check_extension() checks whether the given file has
 * 			appropriate extension type of `.rt`.
 * 			Returns EXIT_FAILURE on failure, EXIT_SUCCESS otherwise.
*/
int	check_extension(char *name, char *extension)
{
	if (name)
	{
		if (ft_strncmp(ft_strrchr(name, DOT), \
			extension, ft_strlen(extension)) == 0)
			return (EXIT_SUCCESS);
	}
	printf("%s%s%s", RED, ERR_INVALID_EXT, RESET);
	return (EXIT_FAILURE);
}

/**
 * @brief	check_file() checks whether the given file has
 * 			appropriate extension type of `.rt`.
 * 			Additionally, it checks whether the file exists and 
 * 			if it's not empty.
 * 
 * @param name			file name
 * @param extension		.rt extension
 * @return int			File descriptor on success, -1 otherwise.
 */
int	check_file(char *name, char *extension)
{
	int		fd;
	char	buf;

	if (check_extension(name, extension) == EXIT_FAILURE)
		return (-1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		printf(ERROR_MSG);
		return (-1);
	}
	if (read(fd, &buf, 1) < 1)
	{
		printf("%sError: %s: %s%s\n", RED, name, ERR_EMPTY, RESET);
		return (-1);
	}
	close(fd);
	return (open(name, O_RDONLY));
}
