/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/06 01:30:37 by kdaniely         ###   ########.fr       */
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
		if (*name == DOT && *(name + 1))
		{
			if (ft_strcmp(ft_strchr(name + 1, DOT), extension) == 0)
				return (EXIT_SUCCESS);
		}
		else if (ft_strcmp(ft_strchr(name, DOT), extension) == 0)
			return (EXIT_SUCCESS);
	}
	printf("%s%s%s", RED, ERR_INVALID_EXT, RESET);
	return (EXIT_FAILURE);
}
