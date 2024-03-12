/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:12:29 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/11 16:57:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_render(t_control *ctl)
{
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->render.mlx_image, 0, 0);
}
