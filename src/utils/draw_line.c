/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:46:29 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/08 19:05:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_line(t_control *ctl, t_point2 from, t_point2 to)
{
	float		scale;
	t_point2	vec;

	vec.x = fabsf(to.x - from.x);
	vec.y = fabsf(to.y - from.y);
	if (!float_equal(vec.x, vec.y) && (vec.x > vec.y))
		scale = vec.x;
	else
		scale = vec.y;
	vec.x /= scale;
	vec.y /= scale;
	while ((int)(from.x - to.x) || (int)(from.y - to.y))
	{
		mlx_pixel_put(ctl->mlx_ptr, ctl->win_ptr, \
			(int)(from.x), (int)(from.y), PLAIN_C);
		from.x += vec.x;
		from.y += vec.y;
	}
}
