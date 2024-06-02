/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:02:48 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/03 02:03:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "miniRT.h"
#include <stdio.h>

void	init_ui(t_control *ctl)
{
	ctl->mlx_ptr = mlx_init();
	ctl->win_u = IMAGE_WIDTH;
	ctl->win_v = IMAGE_HEIGHT;
	new_image(ctl->mlx_ptr, ctl->win_u, ctl->win_v, &ctl->render);
	ctl->win_ptr = mlx_new_window(ctl->mlx_ptr, ctl->win_u, ctl->win_v, NAME);
	printf("\033[32m%s\033[0m\n", HEADER);
	ctl->light_icon.mlx_image = mlx_xpm_file_to_image(ctl->mlx_ptr, \
		"assets/icons/light.xpm", \
		&ctl->light_icon.width, &ctl->light_icon.height);
}
