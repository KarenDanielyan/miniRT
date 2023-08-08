/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/08 01:41:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>
# include "vec3.h"
# include "ray.h"

/* Miscellaneous Defines */
# define ASPECT_RATIO 16/9
# define VP_TO_WIN 100
# define RENDER_FILE "render.ppm"
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

/* Defines for floating-point operations */
# define EPSILON 0.000001

typedef struct s_control	t_control;
typedef struct s_object		t_object;
typedef struct s_camera		t_camera;
typedef struct s_vec3		t_point;
typedef struct s_image		t_image;

typedef enum e_type			t_type;

typedef union u_value		t_value;

enum	e_type
{
	CAMERA,
	AMBIENT,
	PLANE,
	SPHERE
};

struct s_camera
{
	t_point		origin;
	t_vec3		direction;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_point		upper_left;
	float		fov;
	float		focal_length;
};

union u_value
{
	t_camera	camera;
};

struct s_object
{
	t_type	type;
	t_value	value;
};

struct s_image
{
	void	*mlx_image;
	int		*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_control
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_darray	obj_arr;
	t_image		image;
};

#endif