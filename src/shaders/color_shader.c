/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:50:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/04 15:31:36 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	texture_shader(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	(void)hr;
	return (vec3(0.0, 0.0, 0.0));
}

static t_color	checker_shader(t_control *ctl, t_hitrecord *hr)
{
	(void)ctl;
	(void)hr;
	return (vec3(0.0, 0.0, 0.0));
}

t_color	color_shader(t_control *ctl, t_hitrecord *hr)
{
	if (hr->hit->material.properties & TEXTURED)
		return (texture_shader(ctl, hr));
	else if (hr->hit->material.properties & CHECKERED)
		return (checker_shader(ctl, hr));
	else
		return (hr->hit->material.color);
}
