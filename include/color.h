/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:44:49 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 01:19:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "defines.h"
# include "vec3.h"

typedef struct s_vec3	t_color;

static inline void	set_color(int *pixel, t_color color)
{
	*pixel = (int)(get_x(&color) * 255.999) << 16 \
		| (int)(get_y(&color) * 255.999) << 8 \
		| (int)(get_z(&color) * 255.999);
}

#endif