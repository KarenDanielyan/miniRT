/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_mac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:02:48 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/30 21:20:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include "ui.h"
# include "miniRT.h"
# include <stdio.h>

static void	prompt_to_headers(t_control *ctl, char *str1, char *str2);

void	init_ui(t_control *ctl)
{
	ctl->mlx_ptr = mlx_init();
	ctl->win_u = SCREEN_WIDTH;
	ctl->win_v = (int)(ctl->win_u / ((float)ASPECT_RATIO));
	new_image(ctl->mlx_ptr, ctl->win_u, ctl->win_v, &ctl->render);
	ctl->win_ptr = mlx_new_window(ctl->mlx_ptr, ctl->win_u, ctl->win_v, NAME);
	prompt_to_headers(ctl, PREVIEW, HEADER);
}

/* NOTE: We pass do not use the first argument in case of CONSOLE UI Mode */
static void	prompt_to_headers(t_control *ctl, char *str1, char *str2)
{
	(void)ctl;
	(void)str1;
	printf("\033[32m%s\033[0m\n", str2);
}

void	prompt_next_line(t_control *ctl, int color, char *str, ...)
{
	va_list		args;
	char		*tmp;

	(void)ctl;
	(void)color;
	va_start(args, str);
	tmp = get_format_string(str, args);
	pthread_mutex_lock(&ctl->pmux);
	printf("\033[34m%s\033[0m", tmp);
	pthread_mutex_unlock(&ctl->pmux);
	free(tmp);
}
#endif
