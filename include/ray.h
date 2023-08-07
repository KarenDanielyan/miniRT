/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:09:07 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/07 15:14:35 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "defines.h"
# include "vec3.h"

typedef struct s_ray	t_ray;
typedef struct s_vec3	t_point;

struct s_ray
{
	t_point	origin;
	t_vec3	direction;
};

void	new_ray(t_ray *self, t_point origin, t_vec3 direction);

t_point	ray_at(t_ray *r, float t);

#endif