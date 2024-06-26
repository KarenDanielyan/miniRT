/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_constructors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:23:44 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/22 17:36:01 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/**
 * NOTE:	Vector is not allocated inside the function. Just pass vector
 * 			by reference.
*/
void	new_vec3(t_vec3 *v, double e1, double e2, double e3)
{
	v->e[0] = e1;
	v->e[1] = e2;
	v->e[2] = e3;
}

t_vec3	vec3(double e1, double e2, double e3)
{
	t_vec3	v;

	v.e[0] = e1;
	v.e[1] = e2;
	v.e[2] = e3;
	return (v);
}
