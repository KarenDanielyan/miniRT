/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 01:19:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>
# include "vec3.h"
# include "ray.h"

# define NAME "miniRT"

/* Miscellaneous Defines */
# define ASPECT_RATIO 1.777777778
# define VP_TO_WIN 100
# define RENDER_FILE "Images/render.ppm"
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

/* Color Pallete */
# define BACKGROUND_C	0x153243
# define INFO_C			0x284B63
# define STATUS_C		0xFAFAFA //0x00FFFF//0xFE7F2D
# define PLAIN_C		0xFCFAFA
# define NEUTRAL_C		0x000000

/* Defines for floating-point operations */
# define EPSILON 0.000001

/* Defines For UI */
# define HEADER "\
* **************** miniRT ***************** *\n\
*                                           *\n\
*  (c)2023               :::      ::::::::  *\n\
*                      :+:      :+:    :+:  *\n\
*  By: kdaniely      +:+ +:+         +:+    *\n\
*                  +#+  +:+       +#+       *\n\
*                 #+#+#+#+#+   +#+          *\n\
*                     #+#    #+#            *\n\
*                    ###   ########.fr      *\n\
*                                           *\n\
* ***************************************** *"
# define PREVIEW "Image Preview"

# define INFO_WIDTH 300
# define PREVIEW_HEIGHT 50
# define PREVIEW_OFFSET 1

# define MIN_HEIGHT 300
# define MIN_WIDTH 300

# define LINE_SIZE	10

typedef struct s_control	t_control;
typedef struct s_object		t_object;
typedef struct s_camera		t_camera;
typedef struct s_vec3		t_point3;
typedef struct s_image		t_image;
typedef struct s_point2		t_point2;
typedef struct s_ui			t_ui;

typedef enum e_type			t_type;

typedef union u_value		t_value;

struct s_point2
{
	float	x;
	float	y;
};

enum	e_type
{
	CAMERA,
	AMBIENT,
	PLANE,
	SPHERE
};

struct s_camera
{
	t_point3	origin;
	t_vec3		direction;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_point3	upper_left;
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

struct s_ui
{
	t_image	background;
	t_image	preview;
};

struct s_control
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_u;
	int			win_v;
	t_darray	world;
	t_image		render;
	t_ui		ui;
};

#endif