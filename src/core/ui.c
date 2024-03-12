/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:02:48 by kdaniely          #+#    #+#             */
/*   Updated: 2024/03/12 15:58:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "miniRT.h"
#include <stdio.h>

void	init_ui(t_control *ctl)
{
	ctl->mlx_ptr = mlx_init();
	ctl->win_u = SCREEN_WIDTH;
	ctl->win_v = (int)(ctl->win_u / ((float)ASPECT_RATIO));
	new_image(ctl->mlx_ptr, ctl->win_u, ctl->win_v, &ctl->render);
	ctl->win_ptr = mlx_new_window(ctl->mlx_ptr, ctl->win_u, ctl->win_v, NAME);
	printf("\033[32m%s\033[0m\n", HEADER);
}