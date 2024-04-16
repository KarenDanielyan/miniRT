/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/16 19:00:08 by kdaniely         ###   ########.fr       */
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
# define IMAGE_WIDTH	600
# define IMAGE_HEIGHT	600

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

typedef struct s_ray		t_ray;

typedef struct s_matrix4	t_matrix4;

typedef struct s_thread		t_thread;

typedef void				(*t_handler)(t_control *ctl, t_job *job);
typedef void				(*t_compute)(t_control *ctl, t_ray *r, int *pixel);
typedef float				(*t_hit)();

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

#endif