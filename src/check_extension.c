/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/04 18:24:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include <libft.h>

# define DOT '.'
# define EXTENSION ".rt"

/**
 * @brief	check_extension() checks whether the given file has
 * 			appropriate extension type of `.rt`.
 * 			Returns EXIT_FAILURE on failure, EXIT_SUCCESS otherwise.
*/
int	check_extension(char *name)
{
	if (name)
	{
		if (ft_strcmp(ft_strchr(name, DOT), EXTENSION) == 0)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}