/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/13 04:58:26 by kdaniely         ###   ########.fr       */
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
# define IMAGE_WIDTH	800
# define IMAGE_HEIGHT	450

/* Camera Properties */
# define FOCAL_LENGTH	1.0f

/* Ray Tracing Properties */
# define MAX_BOUNCE 5

/* Anti-alsiasing */
# ifndef SSAA
#  define SSAA 10
# endif

/* Miscellaneous Defines */
# define RENDER_FILE "images/render.bmp"
# define EXTENSION ".rt"
# define DOT '.'

# define CHECKER_WIDTH 20
# define CHECKER_HEIGHT 20

/* Error Messages */
# define ERROR_MSG "Error\n"
# define ERR_INVALID_EXT "Error: Invalid file extension.\n"
# define ERR_BADARG "Error: Bad Argument.\n"
# define ERR_INVALID_ARGS "Invalid number of arguments, expected"
# define ERR_INVALID "Invalid "
# define ERR_ARGNUM "occured more than once"
# define ERR_TXTNSUPPORTED \
	"Passing a texture to an object that doesn't support it."

# define WARN_NOMATERIAL "no material specified, assuming default"
# define WARN_INVMATERIAL "WARNING: Invalid material type. Assuming default"
# define WARN_ZEROVEC "Warning: Zero vector detected. Assuming default."

/* Symbols */
# define S_CAMERA "C"
# define S_AMBIENT "A"
# define S_LIGHT "l"
# define S_SPHERE "sp"
# define S_PLANE "pl"
# define S_CYLINDER "cy"
# define S_CONE "cn"
# define S_RECTANGLE "rgl"

# define S_PLASTIC "plastic"
# define S_METALLIC "metallic"
# define S_DIELECTRIC "dielectric"
# define S_DEFAULT "m:default"

/* Colors Escape Codes */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

/* Defines for floating-point operations */
# define EPSILON 0.0001

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
