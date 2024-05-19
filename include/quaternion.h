/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:13:04 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/20 01:42:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "defines.h"
# include "vec3.h"

typedef struct s_tuple4f	t_quaternion;

t_quaternion	new_quaternion(float i, float j, float k, float w);
t_quaternion	quaternion_inverse(t_quaternion *q);

t_quaternion	rodrigues_rotation(t_vec3 *v, float angle);

t_vec3			quarternion_rotate(t_quaternion *q, t_vec3 *v);
#endif