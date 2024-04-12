/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:02:36 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 20:52:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	on_save(t_control *ctl);

int	on_keypress(int key, t_control *ctl)
{
	static int	exec;

	if (key == ESC)
		on_destroy(ctl);
	if (key == S && !(exec & S))
	{
		on_save(ctl);
		exec |= S;
	}
	return (EXIT_SUCCESS);
}

static int	on_save(t_control *ctl)
{
	create_image(RENDER_FILE, ctl->render.data, \
		ctl->render.width, ctl->render.height);
	ft_printf("\033[34mRender saved in %s\033[0m", RENDER_FILE);
	return (EXIT_SUCCESS);
}
