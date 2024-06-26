/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:43:52 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 01:59:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
#include "miniRT.h"

static t_parsetype	argument_check(t_list *tokens, char **point_view, \
	char **vector_orientation, float *h_fov);
static void			make(t_camera *cam, char **pv, char **vo);

void	*parse_camera(t_control *ctl, t_list *tokens, t_parsetype *pt)
{
	char	**pv;
	char	**vo;

	if (ft_lstsize(tokens) != 4)
	{
		printf("%s%s: %s%d%s", RED, S_CAMERA, ERR_INVALID_ARGS, 4, RESET);
		*pt = P_ERROR;
		return (NULL);
	}
	pv = tuple_split(\
		ft_lst_get_by_index(tokens, 1)->content, ',', 3);
	vo = tuple_split(\
		ft_lst_get_by_index(tokens, 2)->content, ',', 3);
	*pt = argument_check(tokens, pv, vo, &ctl->cam.h_fov);
	if (*pt == P_CAMERA)
		make(&ctl->cam, pv, vo);
	free_2d(pv);
	free_2d(vo);
	return (NULL);
}

static t_parsetype	argument_check(t_list *tokens, char **point_view, \
	char **vector_orientation, float *h_fov)
{
	t_parsetype	rv;

	*h_fov = -1;
	rv = P_ERROR;
	if (check_number(ft_lst_get_by_index(tokens, 3)->content) == EXIT_SUCCESS)
		*h_fov = ft_atof(ft_lst_get_by_index(tokens, 3)->content);
	if (!point_view)
		printf("%s%s: %s position.%s\n", RED, S_CAMERA, ERR_INVALID, RESET);
	else if (!vector_orientation)
		printf("%s%s: %s direction.%s\n", RED, S_CAMERA, ERR_INVALID, RESET);
	else if (*h_fov < 0.0 || *h_fov > 179.9)
		printf("%s%s: %s fov.%s\n", RED, S_CAMERA, ERR_INVALID, RESET);
	else
		rv = P_CAMERA;
	return (rv);
}

static void	make(t_camera *cam, char **pv, char **vo)
{
	new_vec3(&cam->center, \
		ft_atof(pv[0]), ft_atof(pv[1]), ft_atof(pv[2]));
	new_vec3(&cam->direction, \
		ft_atof(vo[0]), ft_atof(vo[1]), ft_atof(vo[2]));
	if (float_equal(vec3_length(&cam->direction), 0.0))
	{
		printf("%s%s: %s%s\n", YELLOW, S_CAMERA, WARN_ZEROVEC, RESET);
		cam->direction = vec3(0.0, 0.0, -1.0);
	}
	initialize_camera(cam);
}
