/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:19:13 by armhakob          #+#    #+#             */
/*   Updated: 2024/04/18 21:34:58 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

//TODO: error managment and pretty printing
void	*parse_camera(t_control *ctl, char **splitted_arr)
{
	char	**point_view;
	char	**vector_orientation;
	
	
	if (ft_strlen_2d((const char **)splitted_arr) != 4)
	{
		printf("Invalid number of arguments, expected 4...");
		return (NULL);
	}
	
	point_view = ft_split(splitted_arr[1], ',');
	vector_orientation = ft_split(splitted_arr[2], ',');
	new_vec3(&ctl->cam.center, ft_atof(point_view[0]), ft_atof(point_view[1]), ft_atof(point_view[2]));
	new_vec3(&ctl->cam.direction, ft_atof(vector_orientation[0]), ft_atof(vector_orientation[1]), ft_atof(vector_orientation[2]));
	ctl->cam.h_fov = ft_atof(splitted_arr[3]);
	initialize_camera(&ctl->cam);
	return (NULL);
}