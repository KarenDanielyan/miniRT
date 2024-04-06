/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:46:05 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/06 18:18:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <fcntl.h>
#include <ft_printf.h>

/**
 * @brief	create_image() will create a image in ppm format
 * 			and store the given array of pixels in it.
 * 			It can be used to save rendered scenes.
*/
void	create_image(char *name, int *pixels, int w, int h)
{
	int	fd;
	int	i;
	int	j;

	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	i = 0;
	ft_dprintf(fd, "P3\n%d %d\n%d\n", w, h, 255);
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (j != 0)
				ft_dprintf(fd, "\t");
			ft_dprintf(fd, "%d %d %d", (pixels[i * w + j] & 0xFFFFFF) >> 16, \
				(pixels[i * w + j] & 0xFFFF) >> 8, pixels[i * w + j] & 0xFF);
			j ++;
		}
		ft_dprintf(fd, "\n");
		i ++;
	}
}
