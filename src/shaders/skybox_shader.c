/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox_shader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:47:58 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/02 23:25:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "shapes.h"

t_color	skybox_shader(t_control *ctl, t_ray *ray)
{
	t_light	*ambient;
	t_color	from;
	t_color	to;
	float	a;

	ambient = ft_darray_get_if(&ctl->lights, is_ambient);
	a = 0.5 * (get_y(&ray->direction) + 1.0);
	from = vec3(0.3, 0.3, 0.3);
	to = ambient->color;
	return (vec3_lerp(&from, &to, (1 - a)));
}
