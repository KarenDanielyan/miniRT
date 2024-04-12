/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:36:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 19:09:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "matrix4.h"
# include "vec3.h"
# include "color.h"
# include "ray.h"

typedef struct s_camera
{
	t_point3	center;
	t_point3	pixel_00;
	t_vec3		direction;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_matrix4	camera_to_world;
	float		h_fov;
	float		focal_length;
}	t_camera;

void	initialize_camera(t_camera *cam);

void	look_at(t_point3 *origin, t_vec3 *direction, t_matrix4 *T);
void	render(t_control *ctl, t_job *job);

/* Shaders */
void	ray_shader(t_control *ctl, t_ray *ray, int *pixel);

#endif