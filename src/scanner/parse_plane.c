/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:26:03 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/19 21:06:35 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(char **coords, \
	char **normal, char **rgb);
static void			*make(char **rgb, char **normal, char **coords);

void	*parse_plane(t_list *tokens, t_parsetype *pt)
{
	char	**rgb;
	char	**coords;
	char	**normal;
	void	*hittable;

	hittable = NULL;
	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	rgb = tuple_split(\
		ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	normal = tuple_split(\
		ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	coords = tuple_split(\
		ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	*pt = argument_check(coords, normal, rgb);
	if (*pt == P_OBJECT)
		hittable = make(rgb, normal, coords);
	free_2d(rgb);
	free_2d(coords);
	free_2d(normal);
	return (hittable);
}

static t_parsetype	argument_check(char **coords, \
	char **normal, char **rgb)
{
	if (!coords)
	{
		printf("%s%s%s coordinates.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (!normal)
	{
		printf("%s%s%s normal vector.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (!rgb || check_color(rgb) == EXIT_FAILURE)
	{
		printf("%s%s%s color.%s\n", RED, S_PLANE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	return (P_OBJECT);
}

static void	*make(char **rgb, char **normal, char **coords)
{
	void	*plane;
	void	*hittable;

	plane = new_plane(vec3(ft_atof(coords[0]), ft_atof(coords[1]), \
							ft_atof(coords[3])), \
					vec3(ft_atof(normal[0]), ft_atof(normal[1]), \
							ft_atof(normal[3])));
	hittable = new_hittable(PLANE, &hit_plane, plane);
	((t_hittable *)hittable)->material.color = vec3(ft_map(ft_atof(rgb[0])), \
			ft_map(ft_atof(rgb[1])), ft_map(ft_atof(rgb[2])));
	free(plane);
	return (hittable);
}
