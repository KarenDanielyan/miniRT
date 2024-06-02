/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:36:35 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/03 01:27:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "defines.h"
# include "vec3.h"
# include "material.h"
# include "ray.h"

typedef struct s_camera
{
	int			is_active;
	t_point3	center;
	t_point3	pixel_00;
	t_vec3		direction;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	float		canvas_width;
	float		canvas_height;
	float		h_fov;
	float		focal_length;
}	t_camera;

void	initialize_camera(t_camera *cam);

void	trace(t_control *ctl, t_job *job);

#endif
