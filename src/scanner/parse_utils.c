/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:50:37 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 19:52:06 by armhakob         ###   ########.fr       */
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
		tuple ++;
	}
	if (count != size - 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// TODO: Write Check number.
bool	check_number(char *number)
{
	int	i;
	int	flag_dot;
	
	i = 0;
	flag_dot = 0;
	while (number[i] != '\0')
	{
		if (i == 0 && (number[i] == '-' || number[i] == '+'))
			i ++;
		else if (flag_dot == 0 && number[i] == '.')
			i ++;
		else if (ft_isdigit(number[i]))
			i ++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	**tuple_split(char *tuple, char c, int size)
{
	int		i;
	char	**splited;

	i = 0;
	if (check_tuple(tuple, size) == EXIT_FAILURE)
		return (NULL);
	splited = ft_split(tuple, c);
	while (splited[i])
	{
		if (check_number(splited[i]) == EXIT_FAILURE)
			return (NULL);
		i ++;
	}
	return (splited);
}
