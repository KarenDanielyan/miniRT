/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:12:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/09/01 19:47:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#ifdef __linux__

void	put_render(t_control *ctl)
{
	pthread_mutex_lock(&ctl->winmux);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->render.mlx_image, \
		INFO_WIDTH + PREVIEW_OFFSET, \
		PREVIEW_HEIGHT + PREVIEW_OFFSET);
	pthread_mutex_unlock(&ctl->winmux);
}

#elif __APPLE__

void	put_render(t_control *ctl)
{
	pthread_mutex_lock(&ctl->winmux);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->render.mlx_image, 0, 0);
	pthread_mutex_unlock(&ctl->winmux);
}

#endif
