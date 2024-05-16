/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:42:47 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 20:58:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

/**
	ambient: 1. Symbol -> A, Brightness -> double, RGB -> "x,y,z"
*/
void	*parse_ambient(t_list *tokens, t_parsetype *pt)
{
	void	*rv;
	char	**rgb;

	if (ft_lstsize(tokens) != 3)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 3, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	*pt = P_LIGHTSOURCE;
	rgb = ft_split(ft_lst_get_by_index(tokens, 2)->content, ',');
	rv = new_ambient(ft_atof(ft_lst_get_by_index(tokens, 1)->content), \
					vec3(ft_map(ft_atof(rgb[0])), \
						ft_map(ft_atof(rgb[1])), \
						ft_map(ft_atof(rgb[2]))));
	free_2d(rgb);
	return (rv);
}
