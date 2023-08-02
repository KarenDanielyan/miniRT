/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_window_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:13:41 by kdaniely          #+#    #+#             */
/*   Updated: 2023/08/02 18:29:01 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_get_window_size(void *mlx_ptr, void *win_ptr, int *w, int *h)
{
	t_xvar				*xvar;
	t_win_list			*win;
	XWindowAttributes	attr;

	*w = -1;
	*h = -1;
	if (mlx_ptr && win)
	{
		xvar = (t_xvar *)mlx_ptr;
		win = (t_win_list *)win_ptr;
		XGetWindowAttributes(xvar->display, win->window, &attr);
		*w = attr.width;
		*h = attr.height;
	}
}
