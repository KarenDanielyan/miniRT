/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:30 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 21:03:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

void	*parse_sphere(t_list *tokens, t_parsetype *pt)
{
	void	*shape;
	void	*hittable;
	char	**coordinates;
	char	**rgb;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	*pt = P_OBJECT;
	coordinates = ft_split(ft_lst_get_by_index(tokens, 1)->content, ',');
	rgb = ft_split(ft_lst_get_by_index(tokens, 3)->content, ',');
	shape = new_sphere(vec3(ft_atof(coordinates[0]), ft_atof(coordinates[1]), \
							ft_atof(coordinates[2])), \
							ft_atof(ft_lst_get_by_index(tokens, 2)->content));
	hittable = new_hittable(SPHERE, &hit_sphere, shape);
	((t_hittable *)hittable)->material.color = vec3(ft_map(ft_atof(rgb[0])), \
			ft_map(ft_atof(rgb[1])), ft_map(ft_atof(rgb[2])));
	free(shape);
	free_2d(rgb);
	free_2d(coordinates);
	return (hittable);
}
