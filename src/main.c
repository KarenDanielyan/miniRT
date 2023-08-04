/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:04:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/05 00:34:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>
#include <libft.h>
#include <unistd.h>

#define ERROR_MSG "Error\n"

int	main(int ac, char **av)
{
	t_control	ctl;
	int			i;
	int			j;

	if (ac != 2)
	{
		(void)av;
		printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	ctl.mlx_ptr = mlx_init();
	ctl.win_ptr = mlx_new_window(ctl.mlx_ptr, 256, 256, "Graphical Hello World");
	ctl.image.mlx_image = mlx_new_image(ctl.mlx_ptr, 256, 256);
	ctl.image.data = (int *)mlx_get_data_addr(ctl.image.mlx_image, &ctl.image.bits_per_pixel, \
		&ctl.image.size_line, &ctl.image.endian);
	i = 0;
	printf("Size_line: %d\n", ctl.image.size_line);
	while (i < 256)
	{
		j = 0;
		int	*line = ctl.image.data + i * 256;
		while (j < 256)
		{
			double	r = (double)(j) / 255;
			double	g = (double)(255 - i) / 255;
			double	b = 0.25;
			line[j] = (int)(r * 255.999) << 16 | (int)(g * 255.99) << 8 | (int)(b * 255.99);
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(ctl.mlx_ptr, ctl.win_ptr, ctl.image.mlx_image, 0, 0);
	mlx_loop(ctl.mlx_ptr);
	return (0);
}
