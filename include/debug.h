/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:49:23 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 15:14:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "miniRT.h"
# include "defines.h"
# include "vec3.h"
# include "color.h"
# include "ray.h"

void	graphical_hello_world(t_control *ctl, t_job *job);

void	print_tasks(t_control *ctl);

#endif