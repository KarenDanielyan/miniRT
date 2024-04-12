/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 16:55:48 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "camera.h"
# include "events.h"
# include "utils.h"
# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>

void		scan(t_darray *nodes, char *filename);

void		init_ui(t_control *ctl);

/* Thread Pools */
void		run(t_control *ctl);

/* Utils */
uint64_t	get_time(bool to_init);

static inline int	*get_pixel(t_control *ctl, int i, int j)
{
	return ((ctl->render.data + i * ctl->render.width) + j);
}

void		put_render(t_control *ctl);
void		print_bar(t_control *ctl, int done);
void		fill_image(t_image *image, int color);
void		draw_line(t_control *ctl, t_point2 from, t_point2 to);

#endif