/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:36:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 16:55:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "matrix4.h"
# include "color.h"
# include "ray.h"

void	initialize_camera(t_camera *cam);

void	look_at(t_point3 *origin, t_vec3 *direction, t_matrix4 *T);
void	render(t_control *ctl, t_job *job);

/* Shaders */
void	ray_shader(t_control *ctl, t_ray *ray, int *pixel);

#endif