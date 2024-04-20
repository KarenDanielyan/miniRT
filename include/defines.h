/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/21 01:55:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>
# include <pthread.h>

# define NAME "miniRT"

/* Screen Properties */
# define IMAGE_WIDTH	960
# define IMAGE_HEIGHT	540

/* Camera Properties */
# define FOCAL_LENGTH	1.0f

/* Ray Tracing Properties */
# define MAX_BOUNCE 10

/* Anti-alsiasing */
# ifndef SSAA
#  define SSAA 100
# endif

/* Global Illumination */
# ifndef GI
#  define GI 0
# endif

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
*  (c)2024               :::      ::::::::  *\n\
*                      :+:      :+:    :+:  *\n\
*  By: kdaniely      +:+ +:+         +:+    *\n\
*      armhakob    +#+  +:+       +#+       *\n\
*                 #+#+#+#+#+   +#+          *\n\
*                     #+#    #+#            *\n\
*                    ###   ########.fr      *\n\
*                                           *\n\
* ***************************************** *\n"

typedef struct timeval		t_time;
typedef struct s_task		t_task;
typedef struct s_point		t_point;

typedef struct s_control	t_control;
typedef struct s_image		t_image;
typedef struct s_job		t_job;
typedef struct s_ui			t_ui;

typedef struct s_vec3		t_point3;
typedef struct s_point2		t_point2;
typedef struct s_tuple4f	t_tuple4f;

typedef struct s_ray		t_ray;

typedef struct s_matrix4	t_matrix4;

typedef struct s_thread		t_thread;

typedef void				(*t_handler)(t_control *ctl, t_job *job);
typedef struct s_vec3		(*t_compute)(t_control *ctl, t_ray *r, int bounce);

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

struct s_tuple4f
{
	float	i;
	float	j;
	float	k;
	float	w;
};

#endif
