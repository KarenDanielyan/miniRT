/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:13:04 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 16:31:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "defines.h"
# include "vec3.h"

typedef struct s_tuple4f	t_quaternion;

/* Constructors */

t_quaternion	quaternion(double i, double j, double k, double w);
void			new_quaternion(t_quaternion *q, t_vec3 *u, float w);

/* Operations */

t_quaternion	quaternion_conjugate(t_quaternion *q);

t_quaternion	get_quaternion(t_vec3 *u, t_vec3 *v);
t_quaternion	rodrigues_rotation(t_vec3 *v, float angle);

t_vec3			quarternion_rotate(t_quaternion *q, t_vec3 *v);

#endif