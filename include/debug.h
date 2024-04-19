/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:49:23 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/19 17:52:11 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "miniRT.h"
# include "defines.h"
# include "vec3.h"
# include "material.h"
# include "ray.h"
# include "shapes.h"

void	print_tasks(t_control *ctl);

/* Test Shaders */

t_color	normal_shpere_shader(t_point3 *hit_p, t_sphere *sp);

#endif