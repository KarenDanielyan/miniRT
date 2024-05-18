/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:50:37 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 17:34:35 by armhakob         ###   ########.fr       */
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
bool	check_number(char *number)
{
	int	i;
	int	flag;
	
	i = 0;
	flag = 0;
	while (number[i] != '\0')
	{
		if (number[i] == '.' && flag == 0)
			flag++;
		else if (!ft_isdigit(number[i]) && flag != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**check_and_split(*tuple, char c,int size)
{
	int		i;
	char	**splited;

	i = 0;
	if (check_tuple(tuple) == EXIT_FAILURE)
		return (NULL);
	splited = ft_split(tuple, c);
	while (splited[i])
	{
		if (check_number(splited[i]) == EXIT_FAILURE)
			return (NULL);
	}
	return (splited);
}
