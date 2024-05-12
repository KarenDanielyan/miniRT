/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by armhakob          #+#    #+#             */
/*   Updated: 2024/05/12 17:10:19 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ambient_shader(t_control *ctl, t_hitrecord *hr)
{
	t_light	*a;
	t_color	c;

	a = ft_darray_get_if(&ctl->lights, &get_if_ambient);
	c = vec3_scalar_mult(&a->color, &hr->hit->material.color);
	c = scale_vec3(a->brightness, &c);
	return (c);
}