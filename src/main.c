/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/06 13:06:12 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "color.h"
#include <stdio.h>
#include <libft.h>

static void	graphical_hello_world(t_control *ctl);

int	main(int ac, char **av)
{
	t_control	ctl;

	if (ac != 2)
	{
		(void)av;
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	ctl.mlx_ptr = mlx_init();
	ctl.win_ptr = mlx_new_window(ctl.mlx_ptr, 256, 256, \
		"Graphical Hello World");
	graphical_hello_world(&ctl);
	mlx_hook(ctl.win_ptr, ON_DESTROY, 1L << 2, &on_destroy, &ctl);
	mlx_hook(ctl.win_ptr, ON_KEYDOWN, 1 << 0L, &on_keypress, &ctl);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}

static void	graphical_hello_world(t_control *ctl)
{
	int	i;
	int	j;
	int	*line;

	ctl->image.mlx_image = mlx_new_image(ctl->mlx_ptr, 256, 256);
	ctl->image.data = (int *)mlx_get_data_addr(ctl->image.mlx_image, \
		&ctl->image.bits_per_pixel, \
		&ctl->image.size_line, &ctl->image.endian);
	i = 0;
	while (i < 256)
	{
		j = 0;
		line = ctl->image.data + i * 256;
		while (j < 256)
		{
			set_color((line + j), vec3(j, (255 - i), 0.25 * 255.999));
			j ++;
		}
		i ++;
		usleep(5000);
		mlx_put_image_to_window(ctl->mlx_ptr, \
			ctl->win_ptr, ctl->image.mlx_image, 0, 0);
	}
}
