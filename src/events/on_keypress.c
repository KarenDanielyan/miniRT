/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 02:02:36 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 01:09:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "events.h"

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
	char	*tmp;

	create_image(RENDER_FILE, ctl->render.data, \
		ctl->render.width, ctl->render.height);
	tmp = ft_strjoin("Render saved in ", RENDER_FILE);
	prompt_next_line(ctl, tmp);
	free(tmp);
	return (EXIT_SUCCESS);
}
