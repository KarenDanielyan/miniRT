/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 20:52:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ambient_shader(t_control *ctl, t_hitrecord *hr)
{
	t_light	*a;
	t_color	c;

	a = ft_darray_get_if(&ctl->lights, &is_ambient);
	c = vec3_scalar_mult(&a->color, &hr->hit->material.color);
	c = scale_vec3(a->brightness, &c);
	return (c);
}
