/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:44:19 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/18 19:09:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	new_image(void *mlx_ptr, int width, int height, t_image *image)
{
	image->mlx_image = mlx_new_image(mlx_ptr, width, height);
	image->data = (int *)mlx_get_data_addr(image->mlx_image, \
		&image->bits_per_pixel, \
		&image->size_line, &image->endian);
	image->width = width;
	image->height = height;
}
