/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:50:37 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 03:30:43 by kdaniely         ###   ########.fr       */
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

bool	check_color(char **rgb)
{
	float	c;

	while (*rgb)
	{
		c = ft_atof(*rgb);
		if (c < 0.0 || c > 255.0)
			return (EXIT_FAILURE);
		rgb ++;
	}
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
	char	**splitted;

	i = 0;
	if (check_tuple(tuple, size) == EXIT_FAILURE)
		return (NULL);
	splitted = ft_split(tuple, c);
	if (ft_strlen_2d((const char **)splitted) != size)
	{
		free_2d(splitted);
		return (NULL);
	}
	while (splitted[i])
	{
		if (check_number(splitted[i]) == EXIT_FAILURE)
		{
			free_2d(splitted);
			return (NULL);
		}
		i ++;
	}
	return (splitted);
}

void	check_for_warnings(t_pfields *f, const char *symb)
{
	t_vec3	normal;

	if (f->normal)
		normal = vec3(ft_atof(f->normal[0]), ft_atof(f->normal[1]), \
					ft_atof(f->normal[2]));
	else
		normal = vec3(0, 1, 0);
	if (float_equal(vec3_length(&normal), 0.0))
	{
		printf("%s%s: %s%s\n", YELLOW, symb, WARN_ZEROVEC, RESET);
		free(f->normal[0]);
		free(f->normal[1]);
		free(f->normal[2]);
		f->normal[0] = ft_strdup("0.0");
		f->normal[1] = ft_strdup("1.0");
		f->normal[2] = ft_strdup("0.0");
	}
	if (!f->material)
	{
		printf("%s%s: %s.%s\n", YELLOW, symb, WARN_NOMATERIAL, RESET);
		f->material = ft_strdup("m:default");
	}
}
