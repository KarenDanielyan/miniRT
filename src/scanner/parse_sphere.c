/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:44:30 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/19 19:44:49 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_list *tokens, \
	char **coords, char **rgb);
static void			*make(t_list *tokens, char **coordinates, char **rgb);

void	*parse_sphere(t_list *tokens, t_parsetype *pt)
{
	void	*hittable;
	char	**coordinates;
	char	**rgb;

	hittable = NULL;
	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	coordinates = tuple_split(ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	rgb = tuple_split(ft_lst_get_by_index(tokens, 3)->content, ',', 3);
	*pt = argument_check(tokens, coordinates, rgb);
	if (*pt == P_OBJECT)
		hittable = make(tokens, coordinates, rgb);
	free_2d(rgb);
	free_2d(coordinates);
	return (hittable);
}

static void	*make(t_list *tokens, char **coordinates, char **rgb)
{
	void	*shape;
	void	*hittable;

	shape = new_sphere(vec3(ft_atof(coordinates[0]), \
						ft_atof(coordinates[1]), \
						ft_atof(coordinates[2])), \
					ft_atof(ft_lst_get_by_index(tokens, 2)->content));
	hittable = new_hittable(SPHERE, &hit_sphere, shape);
	((t_hittable *)hittable)->material.color = vec3(ft_map(ft_atof(rgb[0])), \
			ft_map(ft_atof(rgb[1])), ft_map(ft_atof(rgb[2])));
	free(shape);
	return (hittable);
}

static t_parsetype	argument_check(t_list *tokens, \
	char **coords, char **rgb)
{
	float	diameter;

	diameter = -1;
	if (check_number(ft_lst_get_by_index(tokens, 2)->content) == EXIT_SUCCESS)
		diameter = ft_atof(ft_lst_get_by_index(tokens, 2)->content) / 2;
	if (!coords)
	{
		printf("%s%s%scoordinates.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (diameter <= 0.0)
	{
		printf("%s%s%sdiameter.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	else if (!rgb || check_color(rgb) == EXIT_FAILURE)
	{
		printf("%s%s%scolor.%s\n", RED, S_SPHERE, ERR_INVALID, RESET);
		return (P_ERROR);
	}
	return (P_OBJECT);
}
