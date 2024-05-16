/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:43:52 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/16 21:03:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

//TODO: error managment and pretty printing
void	*parse_camera(t_control *ctl, t_list *tokens, t_parsetype *pt)
{
	char	**point_view;
	char	**vector_orientation;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s%d%s", RED, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	*pt = P_CAMERA;
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
