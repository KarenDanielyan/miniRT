/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:17:05 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/10 01:09:38 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_image(t_image *image, int color)
{
	int	i;
	int	j;
	int	*line;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		line = image->data + i * image->width;
		while (j < image->width)
		{
			line[j] = color;
			j ++;
		}
		i ++;
	}
}
