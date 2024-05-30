/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:46:05 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/31 03:20:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <ft_bitmap.h>

/**
 * @brief	create_image() will create a image in ppm format
 * 			and store the given array of pixels in it.
 * 			It can be used to save rendered scenes.
*/
void	create_image(char *name, int *pixels, int w, int h)
{
	t_ftbitmap	*bitmap;

	bitmap = ft_create_bitmap_from_data(w, h, (uint8_t *)pixels);
	if (!bitmap)
	{
		ft_printf("Failed to create bitmap\n");
		return ;
	}
	ft_save_bitmap(bitmap, name);
	ft_destroy_bitmap(bitmap);
}
