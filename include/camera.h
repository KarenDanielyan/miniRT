/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:36:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/09 20:50:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "matrix4.h"
# include "color.h"

typedef struct s_vec3		t_point3;
typedef struct s_matrix4	t_matrix4;
typedef struct s_control	t_control;
typedef struct s_point2		t_point2;
typedef struct s_job		t_job;
typedef struct s_ray		t_ray;

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
void	ray_shader(t_control *ctl, t_point2 *loc);

#endif