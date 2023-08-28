/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_mac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:02:48 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/28 16:37:30 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include "ui.h"
# include "miniRT.h"
# include <stdio.h>

static void	draw_borders(t_control *ctl);
static void	init_background(t_control *ctl);
static void	prompt_to_headers(t_control *ctl, char *str1, char *str2);

void	init_ui(t_control *ctl)
{
	ctl->mlx_ptr = mlx_init();
	ctl->win_u = SCREEN_WIDTH;
	ctl->win_v = (int)(ctl->win_u / ((float)ASPECT_RATIO));
	new_image(ctl->mlx_ptr, ctl->win_u, ctl->win_v, &ctl->render);
	if (ctl->win_v < MIN_HEIGHT)
		ctl->win_v = MIN_HEIGHT;
	if (ctl->win_u < MIN_WIDTH)
		ctl->win_u = MIN_WIDTH;
	ctl->win_u += INFO_WIDTH + 2 * PREVIEW_OFFSET;
	ctl->win_v += PREVIEW_HEIGHT + 2 * PREVIEW_OFFSET;
	ctl->win_ptr = mlx_new_window(ctl->mlx_ptr, ctl->win_u, ctl->win_v, NAME);
	init_background(ctl);
	draw_borders(ctl);
	prompt_to_headers(ctl, PREVIEW, HEADER);
}

static void	draw_borders(t_control *ctl)
{
	t_point2	from;
	t_point2	to;

	from.x = INFO_WIDTH;
	from.y = 0;
	to.x = INFO_WIDTH;
	to.y = ctl->win_v;
	draw_line(ctl, from, to);
	from.x = INFO_WIDTH;
	from.y = PREVIEW_HEIGHT;
	to.x = ctl->win_u;
	to.y = PREVIEW_HEIGHT;
	draw_line(ctl, from, to);
}

static void	init_background(t_control *ctl)
{
	new_image(ctl->mlx_ptr, INFO_WIDTH, ctl->win_v, &ctl->ui.info);
	fill_image(&ctl->ui.info, BACKGROUND_C);
	new_image(ctl->mlx_ptr, ctl->win_u, ctl->win_v, &ctl->ui.background);
	fill_image(&ctl->ui.background, BACKGROUND_C);
	new_image(ctl->mlx_ptr, ctl->win_u - INFO_WIDTH, \
		ctl->win_v - PREVIEW_HEIGHT, &ctl->ui.preview);
	fill_image(&ctl->ui.preview, INFO_C);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->ui.background.mlx_image, 0, 0);
	mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
		ctl->ui.preview.mlx_image, INFO_WIDTH, PREVIEW_HEIGHT);
}

static void	prompt_to_headers(t_control *ctl, char *str1, char *str2)
{
	char	*tmp;
	char	*nl_loc;

	mlx_string_put(ctl->mlx_ptr, ctl->win_ptr, \
		INFO_WIDTH + 20, 0.75 * PREVIEW_HEIGHT, HEADER_C, str1);
	while (str2)
	{
		nl_loc = ft_strchr(str2, '\n');
		if (!nl_loc)
			nl_loc = ft_strchr(str2, 0);
		tmp = ft_substr(str2, 0, (nl_loc - str2));
		prompt_next_line(ctl, HEADER_C, tmp);
		free(tmp);
		if (nl_loc != ft_strchr(str2, 0))
			str2 = nl_loc + 1;
		else
			str2 = NULL;
	}
}

void	prompt_next_line(t_control *ctl, int color, char *str, ...)
{
	static int	offset_u;
	static int	offset_v;
	va_list		args;
	char		*tmp;

	va_start(args, str);
	tmp = get_format_string(str, args);
	if (offset_v == 0)
	{
		offset_u = 10;
		offset_v = LINE_SIZE;
	}
	mlx_string_put(ctl->mlx_ptr, ctl->win_ptr, offset_u, offset_v, \
		color, tmp);
	offset_v += LINE_SIZE;
	if (offset_v >= ctl->win_v)
	{
		mlx_put_image_to_window(ctl->mlx_ptr, ctl->win_ptr, \
			ctl->ui.info.mlx_image, 0, 0);
		offset_v = LINE_SIZE;
	}
	free(tmp);
}
#endif
