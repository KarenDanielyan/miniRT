/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:19:13 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/11 16:29:14 by kdaniely         ###   ########.fr       */
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

void	*parse_ambient(t_control *ctl, t_list *tokens, int *parse_type)
{
	void	*rv;

	*parse_type = P_POINTLIGHT;
	rv = NULL;
	(void)ctl;
	(void)tokens;
	return (rv);
}
