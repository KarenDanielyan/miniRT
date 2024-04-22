/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:30:07 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:35:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	get_x(t_vec3 *self)
{
	return (self->e[0]);
}

double	get_y(t_vec3 *self)
{
	return (self->e[1]);
}

double	get_z(t_vec3 *self)
{
	return (self->e[2]);
}
