/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:16 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 21:08:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

/* Light: position -> brightness -> color */
void	*parse_light(t_list *tokens, t_parsetype *pt)
{
	void	*rv;
	char	**coordinates;
	char	**rgb;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	*pt = P_LIGHTSOURCE;
	coordinates = ft_split(ft_lst_get_by_index(tokens, 1)->content, ',');
	rgb = ft_split(ft_lst_get_by_index(tokens, 3)->content, ',');
	rv = new_light(ft_atof(ft_lst_get_by_index(tokens, 2)->content), \
				vec3(ft_atof(coordinates[0]), \
					ft_atof(coordinates[1]), \
					ft_atof(coordinates[2])), \
				vec3(ft_map(ft_atof(rgb[0])), \
					ft_map(ft_atof(rgb[1])), \
					ft_map(ft_atof(rgb[2]))));
	free_2d(coordinates);
	free_2d(rgb);
	return (rv);
}
