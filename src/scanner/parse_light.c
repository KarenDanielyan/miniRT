/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/18 21:02:29 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_list *tokens, \
	char **coords, char **rgb, float *brightness);

/* Light: position -> brightness -> color */
void	*parse_light(t_list *tokens, t_parsetype *pt)
{
	void	*rv;
	char	**coordinates;
	char	**rgb;
	float	brightness;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	coordinates = tuple_split(ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	rgb = tuple_split(ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	*pt = argument_check(tokens, coordinates, rgb, &brightness);
	if (*pt == P_ERROR)
		return (NULL);
	rv = new_light(brightness, \
				vec3(ft_atof(coordinates[0]), ft_atof(coordinates[1]), \
					ft_atof(coordinates[2])), \
					vec3(ft_map(ft_atof(rgb[0])), ft_map(ft_atof(rgb[1])), \
					ft_map(ft_atof(rgb[2]))));
	free_2d(coordinates);
	free_2d(rgb);
	return (rv);
}

static t_parsetype	argument_check(t_list *tokens, \
	char **coords, char **rgb, float *brightness)
{
	*brightness = -1;
	if (check_number(ft_lst_get_by_index(tokens, 2)->content) == EXIT_SUCCESS)
		*brightness = ft_atof(ft_lst_get_by_index(tokens, 2)->content);
	if (!coords)
	{
		printf("%s%s%scoordinates.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (*brightness < 0.0 || *brightness > 1.0)
	{
		printf("%s%s%sbrightness.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (!rgb || check_color(rgb) == EXIT_FAILURE)
	{
		printf("%s%s%scolor.%s\n", RED, S_LIGHT, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	return (P_LIGHTSOURCE);
}
