/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:38:40 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/10 18:58:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

struct s_light
{
	t_point3	position;
	t_color		color;
}

t_color		diffuse_shader(t_control *ctl, t_hitrecord *hr)
{
	t_color		color;
	struct s_light	l;

	(void)ctl;
	l.position = vec3(-5, 100, -5);
	l.color = vec3(1.0, 1.0, 1.0);
	color = vec3(0, 0, 0);
	if (hr->hit->type == SPHERE)
	{
		
	}
	return (color);
}