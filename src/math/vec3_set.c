/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:32:18 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/23 22:50:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	set_x(t_vec3 *v, float value)
{
	v->e[0] = value;
}

void	set_y(t_vec3 *v, float value)
{
	v->e[1] = value;
}

void	set_z(t_vec3 *v, float value)
{
	v->e[2] = value;
}
