/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:51:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/06 22:12:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <ft_bitmap.h>
#include <mlx.h>

int	on_destroy(t_control *ctl)
{
	mlx_destroy_window(ctl->mlx_ptr, ctl->win_ptr);
	ft_darray_free(&ctl->world, &clear_hittable);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
