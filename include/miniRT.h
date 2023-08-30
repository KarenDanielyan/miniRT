/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 21:46:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "events.h"
# include "utils.h"
# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>

void		scan(t_darray *nodes, char *filename);

void		init_ui(t_control *ctl);

/* Thread Pools */
void		workers_init(t_control *ctl);

/* Utils */
uint64_t	get_time(bool to_init);
void		draw_line(t_control *ctl, t_point2 from, t_point2 to);
void		fill_image(t_image *image, int color);
void		prompt_next_line(t_control *ctl, int color, char *str, ...);

#endif