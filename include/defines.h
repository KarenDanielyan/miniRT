/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/23 22:40:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdarg.h>
# include "vec3.h"
# include "ray.h"

# define NAME "miniRT"

/* Screen Properties */
# define SCREEN_WIDTH 600
# define ASPECT_RATIO 1.5

/* Miscellaneous Defines */
# define RENDER_FILE "Images/render.ppm"
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

/* Color Pallete */
# define BACKGROUND_C	0x153243
# define INFO_C			0x284B63
# define HEADER_C		0x00FF00
# define STATUS_C		0x00FFFF //0xFAFAFA //0x00FFFF//0xFE7F2D
# define PLAIN_C		0xFCFAFA
# define NEUTRAL_C		0x000000

/* Defines for floating-point operations */
# define EPSILON 0.000001

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
* ***************************************** *\n"
# define PREVIEW "Image Preview"

# define INFO_WIDTH 0
# define PREVIEW_HEIGHT 0

typedef struct timeval		t_time;
typedef struct s_task		t_task;
typedef struct s_point		t_point;

typedef struct s_hittable	t_hittable;
typedef struct s_control	t_control;
typedef struct s_camera		t_camera;
typedef struct s_image		t_image;
typedef struct s_job		t_job;
typedef struct s_ui			t_ui;

typedef struct s_vec3		t_point3;
typedef struct s_point2		t_point2;

typedef struct s_thread		t_thread;

typedef void				(*t_handler)(t_control *ctl, t_job *job);
typedef void				(*t_compute)(t_control *ctl, t_point2 *loc, \
	int *pixel);
typedef int					(*t_hit)();

typedef enum e_type			t_type;

typedef union u_geometry	t_geometry;

struct s_point
{
	int		u;
	int		v;
};

struct s_point2
{
	float	x;
	float	y;
};

struct s_task
{
	struct s_point2	from;
	struct s_point2	to;
};

enum	e_type
{
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
	t_point3	pixel_origin;
	float		fov;
	float		focal_length;
};

union u_geometry
{
};

struct s_hittable
{
	t_type		type;
	t_hit		hit_function;
	t_geometry	geometry;
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
	int		info_shift_u;
	int		info_shift_v;
	t_image	background;
	t_image	preview;
	t_image	info;
};

struct s_thread
{
	int			id;
	pthread_t	*thread;
	t_control	*ctl;
};

struct s_job
{
	bool		busy;
	t_point2	from;
	t_point2	to;
	t_handler	job_func;
	t_compute	shader;
};

struct s_control
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_u;
	int				win_v;
	int				worker_c;
	pthread_mutex_t	qmux;
	t_list			*job_q;
	t_thread		*pool;
	t_camera		cam;
	t_darray		world;
	t_image			render;
};

#endif