/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:42 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/04 22:29:01 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <libft.h>

/* Miscellaneous Defines */
# define ERROR_MSG "Error\n"
# define EXTENSION ".rt"
# define DOT '.'

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