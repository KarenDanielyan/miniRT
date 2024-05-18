/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:50:37 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 21:08:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

// TODO: For each number in a tuple check if its a valid number.
bool	check_tuple(char *tuple, int size)
{
	int	count;

	count = 0;
	while (*tuple)
	{
		if (*tuple == ',')
			count ++;
	}
	if (count != size - 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// TODO: Write Check number.
bool	check_number(char *tuple)
{
	return (EXIT_SUCCESS);
}
