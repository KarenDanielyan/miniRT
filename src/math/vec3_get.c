/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:30:07 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/23 22:50:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

float	get_x(t_vec3 *self)
{
	return (self->e[0]);
}

float	get_y(t_vec3 *self)
{
	return (self->e[1]);
}

float	get_z(t_vec3 *self)
{
	return (self->e[2]);
}
