/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:09:07 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 18:55:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "defines.h"
# include "vec3.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

void		new_ray(t_ray *self, t_point3 origin, t_vec3 direction);
void		ray_new(t_ray *self, t_point3 from, t_point3 to);

t_point3	ray_at(t_ray *r, float t);

#endif