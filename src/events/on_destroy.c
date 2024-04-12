/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:51:14 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 20:52:05 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <mlx.h>

int	on_destroy(t_control *ctl)
{
	mlx_destroy_window(ctl->mlx_ptr, ctl->win_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
