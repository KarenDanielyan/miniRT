/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:42:47 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 20:44:38 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_list *tokens, \
	char **rgb, float *brightness);

/**
	ambient: 1. Symbol -> A, Brightness -> double, RGB -> "x,y,z"

	Pipeline:	1. Check if number of arguments is correct.
				2. Check if arguments are valid.
				3. Create the object using the arguments.
*/
void	*parse_ambient(t_list *tokens, t_parsetype *pt)
{
	void	*rv;
	char	**rgb;
	float	brigtness;

	rv = NULL;
	if (ft_lstsize(tokens) != 3)
	{
		printf("%s%s%s%s%d.%s\n", RED, \
			S_AMBIENT, ERR_INVALID_ARGS, " ", 3, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	rgb = tuple_split(ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	*pt = argument_check(tokens, rgb, &brigtness);
	if (*pt == P_LIGHTSOURCE)
	{
		rv = new_ambient(brigtness, \
						vec3(ft_map(ft_atof(rgb[0])), \
							ft_map(ft_atof(rgb[1])), \
							ft_map(ft_atof(rgb[2]))));
	}
	free_2d(rgb);
	return (rv);
}

static t_parsetype	argument_check(t_list *tokens, \
	char **rgb, float *brightness)
{
	*brightness = -1;
	if (check_number(\
		ft_lst_get_by_index(tokens, 1)->content) == EXIT_SUCCESS)
		*brightness = ft_atof(ft_lst_get_by_index(tokens, 1)->content);
	if (!rgb)
	{
		printf("%s%s%scolor.%s\n", RED, S_AMBIENT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (*brightness < 0.0 || *brightness > 1.0)
	{
		printf("%s%s%sbrightness.%s\n", RED, S_AMBIENT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (check_color(rgb) == EXIT_FAILURE)
	{
		printf("%s%s%scolor.%s\n", RED, S_AMBIENT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	return (P_LIGHTSOURCE);
}
