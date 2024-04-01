/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/01 18:29:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>
# include <pthread.h>
# include "vec3.h"
# include "ray.h"
# include "camera.h"

# define NAME "miniRT"

/* Screen Properties */
# define IMAGE_WIDTH	600
# define IMAGE_HEIGHT	400

/* Camera Properties */
# define FOCAL_LENGTH	1.0f

/* Miscellaneous Defines */
# define RENDER_FILE "Images/render.ppm"
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

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

typedef struct timeval		t_time;
typedef struct s_task		t_task;
typedef struct s_point		t_point;

typedef struct s_hittable	t_hittable;
typedef struct s_control	t_control;
typedef struct s_image		t_image;
typedef struct s_job		t_job;
typedef struct s_ui			t_ui;

typedef struct s_vec3		t_point3;
typedef struct s_point2		t_point2;

typedef struct s_matrix4	t_matrix4;

typedef struct s_thread		t_thread;

typedef void				(*t_handler)(t_control *ctl, t_job *job);
typedef void				(*t_compute)(t_control *ctl, t_point2 *loc, \
	int *pixel);
typedef int					(*t_hit)();

typedef enum e_type			t_type;

typedef union u_shape		t_shape;

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

/* TODO: Figure out if I need matrix structure or not.
struct	s_matrix44
{
	float		m[4][4];
};
*/

enum	e_type
{
	PLANE,
	SPHERE
};

union u_shape
{
};

struct s_hittable
{
	t_type	type;
	t_hit	hit_function;
	t_shape	shape;
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