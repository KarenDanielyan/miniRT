/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/06 14:43:54 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>
# include <stdint.h>
# include <stdbool.h>

/* Miscellaneous Defines */
# define RENDER_FILE "render.ppm"
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

/* Defines for floating-point operations */
# define EPSILON 0.000001

typedef struct s_object		t_object;
typedef struct s_control	t_control;
typedef struct s_image		t_image;

struct s_object
{
	int	dummy;
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