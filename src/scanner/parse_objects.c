/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:19:13 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 20:14:47 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

//TODO: error managment and pretty printing
void	*parse_camera(t_control *ctl, t_list *tokens, int *parse_type)
{
	char	**point_view;
	char	**vector_orientation;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*parse_type = P_ERRTYPE;
		return (NULL);
	}
	*parse_type = P_CAMERA;
	point_view = ft_split(ft_lst_get_by_index(tokens, 1)->content, ',');
	vector_orientation = ft_split(ft_lst_get_by_index(tokens, 2)->content, ',');
	new_vec3(&ctl->cam.center, \
		ft_atof(point_view[0]), ft_atof(point_view[1]), ft_atof(point_view[2]));
	new_vec3(&ctl->cam.direction, \
		ft_atof(vector_orientation[0]), ft_atof(vector_orientation[1]), \
		ft_atof(vector_orientation[2]));
	ctl->cam.h_fov = ft_atof(ft_lst_get_by_index(tokens, 3)->content);
	initialize_camera(&ctl->cam);
	free_2d(point_view);
	free_2d(vector_orientation);
	return (NULL);
}

/**
	ambient: 1. Symbol -> A, Brightness -> double, RGB -> "x,y,z"
*/
void	*parse_ambient(t_control *ctl, t_list *tokens, int *parse_type)
{
	void	*rv;
	char	**rgb;

	(void)ctl;
	if (ft_lstsize(tokens) != 3)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*parse_type = P_ERRTYPE;
		return (NULL);
	}
	*parse_type = P_POINTLIGHT;
	rgb = ft_split(ft_lst_get_by_index(tokens, 2)->content, ',');
	rv = new_ambient(ft_atof(ft_lst_get_by_index(tokens, 1)->content), \
					vec3(ft_map(ft_atof(rgb[0])), \
						ft_map(ft_atof(rgb[1])), \
						ft_map(ft_atof(rgb[2]))));
	free_2d(rgb);
	return (rv);
}

void	*parse_light(t_control *ctl, t_list *tokens, int *parse_type)
{
	void	*rv;
	char	**coordinates;
	char	**rgb;

	(void)ctl;
	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*parse_type = P_ERRTYPE;
		return (NULL);
	}
	*parse_type = P_POINTLIGHT;
	coordinates = ft_split(ft_lst_get_by_index(tokens, 1)->content, ',');
	rgb = ft_split(ft_lst_get_by_index(tokens, 3)->content, ',');
	rv = new_light(vec3(ft_atof(coordinates[0]), ft_atof(coordinates[1]), \
						ft_atof(coordinates[2])), \
					ft_atof(ft_lst_get_by_index(tokens, 2)->content),
					vec3(ft_map(ft_atof(rgb[0])), \
						ft_map(ft_atof(rgb[1])), \
						ft_map(ft_atof(rgb[2]))));
	free_2d(coordinates);
	free_2d(rgb);
	return (rv);
}
